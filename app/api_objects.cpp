

#include <graphene/app/api_objects.hpp>
#include <graphene/app/util.hpp>

namespace graphene { namespace app {

market_ticker::market_ticker(const market_ticker_object& mto,
                             const fc::time_point_sec& now,
                             const asset_object& asset_base,
                             const asset_object& asset_quote,
                             const order_book& orders)
{
   time = now;
   base = asset_base.symbol;
   quote = asset_quote.symbol;
   percent_change = "0";
   lowest_ask = "0";
   highest_bid = "0";

   fc::uint128_t bv;
   fc::uint128_t qv;
   price latest_price = asset( mto.latest_base, mto.base ) / asset( mto.latest_quote, mto.quote );
   if( mto.base != asset_base.id )
      latest_price = ~latest_price;
   latest = price_to_string( latest_price, asset_base, asset_quote );
   if( mto.last_day_base != 0 && mto.last_day_quote != 0 // has trade data before 24 hours
       && ( mto.last_day_base != mto.latest_base || mto.last_day_quote != mto.latest_quote ) ) // price changed
   {
      price last_day_price = asset( mto.last_day_base, mto.base ) / asset( mto.last_day_quote, mto.quote );
      if( mto.base != asset_base.id )
         last_day_price = ~last_day_price;
      percent_change = price_diff_percent_string( last_day_price, latest_price );
   }
   if( asset_base.id == mto.base )
   {
      bv = mto.base_volume;
      qv = mto.quote_volume;
   }
   else
   {
      bv = mto.quote_volume;
      qv = mto.base_volume;
   }
   base_volume = uint128_amount_to_string( bv, asset_base.precision );
   quote_volume = uint128_amount_to_string( qv, asset_quote.precision );

   if(!orders.asks.empty())
      lowest_ask = orders.asks[0].price;
   if(!orders.bids.empty())
      highest_bid = orders.bids[0].price;
}

market_ticker::market_ticker(const fc::time_point_sec& now,
                             const asset_object& asset_base,
                             const asset_object& asset_quote)
{
   time = now;
   base = asset_base.symbol;
   quote = asset_quote.symbol;
   latest = "0";
   lowest_ask = "0";
   highest_bid = "0";
   percent_change = "0";
   base_volume = "0";
   quote_volume = "0";
}

} } // graphene::app
