
#pragma once

#include <fc/uint128.hpp>

namespace graphene {
namespace protocol {
   struct price;
}
namespace chain {
   class asset_object;
}

namespace app {
   std::string uint128_amount_to_string( const fc::uint128_t& amount, const uint8_t precision );
   std::string price_to_string( const graphene::protocol::price& _price,
                                const uint8_t base_precision,
                                const uint8_t quote_precision );
   std::string price_to_string( const graphene::protocol::price& _price,
                                const graphene::chain::asset_object& _base,
                                const graphene::chain::asset_object& _quote );
   std::string price_diff_percent_string( const graphene::protocol::price& old_price,
                                          const graphene::protocol::price& new_price );
} }
