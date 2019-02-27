// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "person-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/mysql/traits.hxx>
#include <odb/mysql/database.hxx>
#include <odb/mysql/transaction.hxx>
#include <odb/mysql/connection.hxx>
#include <odb/mysql/statement.hxx>
#include <odb/mysql/statement-cache.hxx>
#include <odb/mysql/simple-object-statements.hxx>
#include <odb/mysql/container-statements.hxx>
#include <odb/mysql/exceptions.hxx>
#include <odb/mysql/enum.hxx>

namespace odb
{
  // person
  //

  struct access::object_traits_impl< ::person, id_mysql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      mysql::connection&,
      image_type&,
      id_image_type&,
      mysql::binding&,
      mysql::binding&)
    {
    }
  };

  access::object_traits_impl< ::person, id_mysql >::id_type
  access::object_traits_impl< ::person, id_mysql >::
  id (const id_image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::person, id_mysql >::version_type
  access::object_traits_impl< ::person, id_mysql >::
  version (const image_type& i)
  {
    version_type v;
    {
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        v,
        i.version_value,
        i.version_null);
    }

    return v;
  }

  bool access::object_traits_impl< ::person, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // id_
    //
    t[0UL] = 0;

    // version_
    //
    t[1UL] = 0;

    // first_
    //
    if (t[2UL])
    {
      i.first_value.capacity (i.first_size);
      grew = true;
    }

    // last_
    //
    if (t[3UL])
    {
      i.last_value.capacity (i.last_size);
      grew = true;
    }

    // age_
    //
    t[4UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::person, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // id_
    //
    if (sk != statement_update)
    {
      b[n].buffer_type = MYSQL_TYPE_LONGLONG;
      b[n].is_unsigned = 1;
      b[n].buffer = &i.id_value;
      b[n].is_null = &i.id_null;
      n++;
    }

    // version_
    //
    if (sk == statement_select)
    {
      b[n].buffer_type = MYSQL_TYPE_LONGLONG;
      b[n].is_unsigned = 1;
      b[n].buffer = &i.version_value;
      b[n].is_null = &i.version_null;
      n++;
    }

    // first_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.first_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.first_value.capacity ());
    b[n].length = &i.first_size;
    b[n].is_null = &i.first_null;
    n++;

    // last_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.last_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.last_value.capacity ());
    b[n].length = &i.last_size;
    b[n].is_null = &i.last_null;
    n++;

    // age_
    //
    b[n].buffer_type = MYSQL_TYPE_SHORT;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.age_value;
    b[n].is_null = &i.age_null;
    n++;
  }

  void access::object_traits_impl< ::person, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i, bool bv)
  {
    std::size_t n (0);
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
    if (bv)
    {
      n += 1;

      b[n].buffer_type = MYSQL_TYPE_LONGLONG;
      b[n].is_unsigned = 1;
      b[n].buffer = &i.version_value;
      b[n].is_null = &i.version_null;
    }
  }

  bool access::object_traits_impl< ::person, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

    // id_
    //
    if (sk == statement_insert)
    {
      long unsigned int const& v =
        o.id_;

      bool is_null (false);
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_image (
        i.id_value, is_null, v);
      i.id_null = is_null;
    }

    // first_
    //
    {
      ::std::string const& v =
        o.first_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.first_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.first_value,
        size,
        is_null,
        v);
      i.first_null = is_null;
      i.first_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.first_value.capacity ());
    }

    // last_
    //
    {
      ::std::string const& v =
        o.last_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.last_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.last_value,
        size,
        is_null,
        v);
      i.last_null = is_null;
      i.last_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.last_value.capacity ());
    }

    // age_
    //
    {
      short unsigned int const& v =
        o.age_;

      bool is_null (false);
      mysql::value_traits<
          short unsigned int,
          mysql::id_ushort >::set_image (
        i.age_value, is_null, v);
      i.age_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::person, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // id_
    //
    {
      long unsigned int& v =
        o.id_;

      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        v,
        i.id_value,
        i.id_null);
    }

    // version_
    //
    {
      long unsigned int& v =
        o.version_;

      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        v,
        i.version_value,
        i.version_null);
    }

    // first_
    //
    {
      ::std::string& v =
        o.first_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.first_value,
        i.first_size,
        i.first_null);
    }

    // last_
    //
    {
      ::std::string& v =
        o.last_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.last_value,
        i.last_size,
        i.last_null);
    }

    // age_
    //
    {
      short unsigned int& v =
        o.age_;

      mysql::value_traits<
          short unsigned int,
          mysql::id_ushort >::set_value (
        v,
        i.age_value,
        i.age_null);
    }
  }

  void access::object_traits_impl< ::person, id_mysql >::
  init (id_image_type& i, const id_type& id, const version_type* v)
  {
    {
      bool is_null (false);
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_image (
        i.id_value, is_null, id);
      i.id_null = is_null;
    }

    if (v != 0)
    {
      bool is_null (false);
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_image (
        i.version_value, is_null, (*v));
      i.version_null = is_null;
    }
  }

  const char access::object_traits_impl< ::person, id_mysql >::persist_statement[] =
  "INSERT INTO `person` "
  "(`id`, "
  "`version`, "
  "`first`, "
  "`last`, "
  "`age`) "
  "VALUES "
  "(?, 1, ?, ?, ?)";

  const char access::object_traits_impl< ::person, id_mysql >::find_statement[] =
  "SELECT "
  "`person`.`id`, "
  "`person`.`version`, "
  "`person`.`first`, "
  "`person`.`last`, "
  "`person`.`age` "
  "FROM `person` "
  "WHERE `person`.`id`=?";

  const char access::object_traits_impl< ::person, id_mysql >::update_statement[] =
  "UPDATE `person` "
  "SET "
  "`version`=`version`+1, "
  "`first`=?, "
  "`last`=?, "
  "`age`=? "
  "WHERE `id`=? AND `version`=?";

  const char access::object_traits_impl< ::person, id_mysql >::erase_statement[] =
  "DELETE FROM `person` "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::person, id_mysql >::optimistic_erase_statement[] =
  "DELETE FROM `person` "
  "WHERE `id`=? AND `version`=?";

  void access::object_traits_impl< ::person, id_mysql >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    im.id_value = 0;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
        sts.optimistic_id_image_binding ().version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj.id_ = id (sts.id_image ());

    obj.version_ = 1;

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::person, id_mysql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;
    using mysql::update_statement;

    callback (db, obj, callback_event::pre_update);

    mysql::transaction& tr (mysql::transaction::current ());
    mysql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.id_);
    const version_type& v (
      obj.version_);
    id_image_type& idi (sts.id_image ());
    init (idi, id, &v);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
        sts.optimistic_id_image_binding ().version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_changed ();

    const_cast< object_type& > (obj).version_++;

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::person, id_mysql >::
  erase (database& db, const id_type& id)
  {
    using namespace mysql;

    ODB_POTENTIALLY_UNUSED (db);

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
      sts.optimistic_id_image_binding ().version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  void access::object_traits_impl< ::person, id_mysql >::
  erase (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db, obj, callback_event::pre_erase);

    const id_type& id  (
      obj.id_);

    const version_type& v (
      obj.version_);
    id_image_type& i (sts.id_image ());
    init (i, id, &v);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () ||
        idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
      sts.optimistic_id_image_binding ().version++;
    }

    if (sts.optimistic_erase_statement ().execute () != 1)
      throw object_changed ();

    pointer_cache_traits::erase (db, id);
    callback (db, obj, callback_event::post_erase);
  }

  access::object_traits_impl< ::person, id_mysql >::pointer_type
  access::object_traits_impl< ::person, id_mysql >::
  find (database& db, const id_type& id)
  {
    using namespace mysql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::person, id_mysql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::person, id_mysql >::
  reload (database& db, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.id_);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    if (version (sts.image ()) == obj.version_)
      return true;

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::person, id_mysql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mysql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
      sts.optimistic_id_image_binding ().version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }
}

#include <odb/post.hxx>
