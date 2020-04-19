#
#pragma once

#include <graphene/protocol/types.hpp>

namespace graphene { namespace chain { using namespace protocol; } }

GRAPHENE_DEFINE_IDS(chain, implementation_ids, impl_,
                    (global_property)
                    (dynamic_global_property)
                    (reserved0)
                    (asset_dynamic_data)
                    (asset_bitasset_data)
                    (account_balance)
                    (account_statistics)
                    (transaction_history)
                    (block_summary)
                    (account_transaction_history)
                    (blinded_balance)
                    (chain_property)
                    (witness_schedule)
                    (budget_record)
                    (special_authority)
                    (buyback)
                    (fba_accumulator)
                    (collateral_bid))
