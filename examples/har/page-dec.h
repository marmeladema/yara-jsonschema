begin_declarations;
  declare_string("startedDateTime");
  declare_string("id");
  declare_string("title");
  begin_struct("pageTimings");
    declare_float("onContentLoad");
    declare_float("onLoad");
    declare_string("comment");
  end_struct("pageTimings");
  declare_string("comment");
end_declarations;