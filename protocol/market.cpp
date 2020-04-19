#
#include <graphene/protocol/market.hpp>

#include <fc/io/raw.hpp>

namespace graphene { namespace protocol {

void limit_order_create_operation::validate()const
{
   FC_ASSERT( amount_to_sell.asset_id != min_to_receive.asset_id );
   FC_ASSERT( fee.amount >= 0 );
   FC_ASSERT( amount_to_sell.amount > 0 );
   FC_ASSERT( min_to_receive.amount > 0 );
}

void limit_order_cancel_operation::validate()const
{
   FC_ASSERT( fee.amount >= 0 );
}

void call_order_update_operation::validate()const
{ try {
   FC_ASSERT( fee.amount >= 0 );
   FC_ASSERT( delta_collateral.asset_id != delta_debt.asset_id );
   FC_ASSERT( delta_collateral.amount != 0 || delta_debt.amount != 0 );

   // note: no validation is needed for extensions so far: the only attribute inside is target_collateral_ratio

} FC_CAPTURE_AND_RETHROW((*this)) }

void bid_collateral_operation::validate()const
{ try {
   FC_ASSERT( fee.amount >= 0 );
   FC_ASSERT( debt_covered.amount == 0 || (debt_covered.amount > 0 && additional_collateral.amount > 0) );
} FC_CAPTURE_AND_RETHROW((*this)) }

} } // graphene::protocol

GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::call_order_update_operation::options_type )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::limit_order_create_operation::fee_parameters_type )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::limit_order_cancel_operation::fee_parameters_type )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::call_order_update_operation::fee_parameters_type )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::bid_collateral_operation::fee_parameters_type )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::limit_order_create_operation )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::limit_order_cancel_operation )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::call_order_update_operation )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::bid_collateral_operation )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::fill_order_operation )
GRAPHENE_IMPLEMENT_EXTERNAL_SERIALIZATION( graphene::protocol::execute_bid_operation )
