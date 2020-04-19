#
#include <graphene/protocol/address.hpp>
#include <graphene/protocol/pts_address.hpp>
#include <fc/crypto/base58.hpp>
#include <algorithm>

#include <fc/io/raw.hpp>

namespace graphene { namespace protocol {

   address::address( const std::string& base58str )
   {
      std::string prefix( GRAPHENE_ADDRESS_PREFIX );
      FC_ASSERT( is_valid( base58str, prefix ), "${str}", ("str",base58str) );

      std::vector<char> v = fc::from_base58( base58str.substr( prefix.size() ) );
      memcpy( (char*)addr._hash, v.data(), std::min<size_t>( v.size()-4, sizeof( addr ) ) );
   }

   bool address::is_valid( const std::string& base58str, const std::string& prefix )
   {
      const size_t prefix_len = prefix.size();
      if( base58str.size() <= prefix_len )
          return false;
      if( base58str.substr( 0, prefix_len ) != prefix )
          return false;
      std::vector<char> v;
      try
      {
		     v = fc::from_base58( base58str.substr( prefix_len ) );
      }
      catch( const fc::parse_error_exception& e )
      {
        return false;
      }

      if( v.size() != sizeof( fc::ripemd160 ) + 4 )
          return false;

      const fc::ripemd160 checksum = fc::ripemd160::hash( v.data(), v.size() - 4 );
      if( memcmp( v.data() + 20, (char*)checksum._hash, 4 ) != 0 )
          return false;

      return true;
   }

   address::address( const fc::ecc::public_key& pub )
   {
       auto dat = pub.serialize();
       addr = fc::ripemd160::hash( fc::sha512::hash( (char*) dat.data(), dat.size() ) );
   }

   address::address( const pts_address& ptsaddr )
   {
       addr = fc::ripemd160::hash( (char*)&ptsaddr, sizeof( ptsaddr ) );
   }

   address::address( const fc::ecc::public_key_data& pub )
   {
       addr = fc::ripemd160::hash( fc::sha512::hash( (char*) pub.data(), pub.size() ) );
   }

   address::address( const graphene::protocol::public_key_type& pub )
   {
       addr = fc::ripemd160::hash( fc::sha512::hash( (char*) pub.key_data.data(), pub.key_data.size() ) );
   }

   address::operator std::string()const
   {
        char bin_addr[24];
        static_assert( sizeof(bin_addr) >= sizeof(addr) + 4, "address size mismatch" );
        memcpy( bin_addr, addr.data(), sizeof(addr) );
        auto checksum = fc::ripemd160::hash( addr.data(), sizeof(addr) );
        memcpy( bin_addr + sizeof(addr), (char*)&checksum._hash[0], 4 );
        return GRAPHENE_ADDRESS_PREFIX + fc::to_base58( bin_addr, sizeof(bin_addr) );
   }

} } // namespace graphene::protocol

namespace fc
{
    void to_variant( const graphene::protocol::address& var,  variant& vo, uint32_t max_depth )
    {
        vo = std::string(var);
    }
    void from_variant( const variant& var,  graphene::protocol::address& vo, uint32_t max_depth )
    {
        vo = graphene::protocol::address( var.as_string() );
    }
}

GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::address )
