#
#pragma once
#include <fc/exception/exception.hpp>

namespace graphene { namespace net {
   // registered in node.cpp 
   
   FC_DECLARE_EXCEPTION( net_exception, 90000 )
   FC_DECLARE_DERIVED_EXCEPTION( send_queue_overflow,                 net_exception, 90001 ) 
   FC_DECLARE_DERIVED_EXCEPTION( insufficient_relay_fee,              net_exception, 90002 )
   FC_DECLARE_DERIVED_EXCEPTION( already_connected_to_requested_peer, net_exception, 90003 )
   FC_DECLARE_DERIVED_EXCEPTION( block_older_than_undo_history,       net_exception, 90004 )
   FC_DECLARE_DERIVED_EXCEPTION( peer_is_on_an_unreachable_fork,      net_exception, 90005 )
   FC_DECLARE_DERIVED_EXCEPTION( unlinkable_block_exception,          net_exception, 90006 )
   FC_DECLARE_DERIVED_EXCEPTION( block_timestamp_in_future_exception, net_exception, 90007 )

} }
