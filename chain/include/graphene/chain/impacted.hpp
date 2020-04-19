#
#pragma once

#include <fc/container/flat.hpp>
#include <graphene/protocol/operations.hpp>
#include <graphene/protocol/transaction.hpp>
#include <graphene/protocol/types.hpp>

namespace graphene { namespace chain {

void operation_get_impacted_accounts(
   const graphene::chain::operation& op,
   fc::flat_set<graphene::chain::account_id_type>& result );

void transaction_get_impacted_accounts(
   const graphene::chain::transaction& tx,
   fc::flat_set<graphene::chain::account_id_type>& result
   );

} } // graphene::app