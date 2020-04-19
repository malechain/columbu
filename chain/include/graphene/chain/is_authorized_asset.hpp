#
#pragma once

namespace graphene { namespace chain {

class account_object;
class asset_object;
class database;

namespace detail {

bool _is_authorized_asset(const database& d, const account_object& acct, const asset_object& asset_obj);

}

/**
 * @return true if the account is whitelisted and not blacklisted to transact in the provided asset; false
 * otherwise.
 */

inline bool is_authorized_asset(const database& d, const account_object& acct, const asset_object& asset_obj)
{
   bool fast_check = !(asset_obj.options.flags & white_list);
   fast_check &= !(acct.allowed_assets.valid());

   if( fast_check )
      return true;

   bool slow_check = detail::_is_authorized_asset( d, acct, asset_obj );
   return slow_check;
}

} }
