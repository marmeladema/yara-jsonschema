char path[4096] = {0}, part[128] = {0};
json_t *value __attribute__((unused));
size_t index __attribute__((unused));
const char *key __attribute__((unused));
const char *str __attribute__((unused));
  {
    size_t pathlen = strlen(path);
    if(pathlen == 0) {
      snprintf(path+pathlen, sizeof(path)-pathlen, "startedDateTime");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".startedDateTime");
    }
    value = node;
    json_t *node = json_object_get(value, "startedDateTime");
    if(node) {
      str = json_string_value(node);
      if(str) set_string(str, module_object, path);
    }
    path[pathlen] = 0;
  }
  {
    size_t pathlen = strlen(path);
    if(pathlen == 0) {
      snprintf(path+pathlen, sizeof(path)-pathlen, "id");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".id");
    }
    value = node;
    json_t *node = json_object_get(value, "id");
    if(node) {
      str = json_string_value(node);
      if(str) set_string(str, module_object, path);
    }
    path[pathlen] = 0;
  }
  {
    size_t pathlen = strlen(path);
    if(pathlen == 0) {
      snprintf(path+pathlen, sizeof(path)-pathlen, "title");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".title");
    }
    value = node;
    json_t *node = json_object_get(value, "title");
    if(node) {
      str = json_string_value(node);
      if(str) set_string(str, module_object, path);
    }
    path[pathlen] = 0;
  }
  {
    size_t pathlen = strlen(path);
    if(pathlen == 0) {
      snprintf(path+pathlen, sizeof(path)-pathlen, "pageTimings");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".pageTimings");
    }
    value = node;
    json_t *node = json_object_get(value, "pageTimings");
    if(node) {
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "onContentLoad");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".onContentLoad");
      }
      value = node;
      json_t *node = json_object_get(value, "onContentLoad");
      if(node) {
        set_float(json_real_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "onLoad");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".onLoad");
      }
      value = node;
      json_t *node = json_object_get(value, "onLoad");
      if(node) {
        set_float(json_real_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "comment");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".comment");
      }
      value = node;
      json_t *node = json_object_get(value, "comment");
      if(node) {
        str = json_string_value(node);
        if(str) set_string(str, module_object, path);
      }
      path[pathlen] = 0;
    }
    path[pathlen] = 0;
  }
  {
    size_t pathlen = strlen(path);
    if(pathlen == 0) {
      snprintf(path+pathlen, sizeof(path)-pathlen, "comment");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".comment");
    }
    value = node;
    json_t *node = json_object_get(value, "comment");
    if(node) {
      str = json_string_value(node);
      if(str) set_string(str, module_object, path);
    }
    path[pathlen] = 0;
  }
