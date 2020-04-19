#
#pragma once
#include <graphene/chain/evaluator.hpp>
#include <graphene/chain/account_object.hpp>

namespace graphene { namespace chain {

class account_create_evaluator : public evaluator<account_create_evaluator>
{
public:
   typedef account_create_operation operation_type;

   void_result do_evaluate( const account_create_operation& o );
   object_id_type do_apply( const account_create_operation& o ) ;
};

class account_update_evaluator : public evaluator<account_update_evaluator>
{
public:
   typedef account_update_operation operation_type;

   void_result do_evaluate( const account_update_operation& o );
   void_result do_apply( const account_update_operation& o );

   const account_object* acnt;
};

class account_upgrade_evaluator : public evaluator<account_upgrade_evaluator>
{
public:
   typedef account_upgrade_operation operation_type;

   void_result do_evaluate(const operation_type& o);
   void_result do_apply(const operation_type& o);

   const account_object* account;
};

class account_whitelist_evaluator : public evaluator<account_whitelist_evaluator>
{
public:
   typedef account_whitelist_operation operation_type;

   void_result do_evaluate( const account_whitelist_operation& o);
   void_result do_apply( const account_whitelist_operation& o);

   const account_object* listed_account;
};

} } // graphene::chain
