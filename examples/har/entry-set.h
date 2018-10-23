char path[4096] = {0}, part[128] = {0};
json_t *value __attribute__((unused));
size_t index __attribute__((unused));
const char *key __attribute__((unused));
const char *str __attribute__((unused));
  {
    size_t pathlen = strlen(path);
    if(pathlen == 0) {
      snprintf(path+pathlen, sizeof(path)-pathlen, "pageref");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".pageref");
    }
    value = node;
    json_t *node = json_object_get(value, "pageref");
    if(node) {
      str = json_string_value(node);
      if(str) set_string(str, module_object, path);
    }
    path[pathlen] = 0;
  }
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
      snprintf(path+pathlen, sizeof(path)-pathlen, "time");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".time");
    }
    value = node;
    json_t *node = json_object_get(value, "time");
    if(node) {
      set_float(json_real_value(node), module_object, path);
    }
    path[pathlen] = 0;
  }
  {
    size_t pathlen = strlen(path);
    if(pathlen == 0) {
      snprintf(path+pathlen, sizeof(path)-pathlen, "request");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".request");
    }
    value = node;
    json_t *node = json_object_get(value, "request");
    if(node) {
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "method");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".method");
      }
      value = node;
      json_t *node = json_object_get(value, "method");
      if(node) {
        str = json_string_value(node);
        if(str) set_string(str, module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "url");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".url");
      }
      value = node;
      json_t *node = json_object_get(value, "url");
      if(node) {
        str = json_string_value(node);
        if(str) set_string(str, module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "httpVersion");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".httpVersion");
      }
      value = node;
      json_t *node = json_object_get(value, "httpVersion");
      if(node) {
        str = json_string_value(node);
        if(str) set_string(str, module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "cookies");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".cookies");
      }
      value = node;
      json_t *node = json_object_get(value, "cookies");
      if(node) {
      }
      json_array_foreach(node, index, value) {
        size_t pathlen = strlen(path);
        snprintf(path+pathlen, sizeof(path)-pathlen, "[%zu]", index);
        json_t *node = value;
        if(node) {
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "name");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".name");
          }
          value = node;
          json_t *node = json_object_get(value, "name");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "value");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".value");
          }
          value = node;
          json_t *node = json_object_get(value, "value");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "path");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".path");
          }
          value = node;
          json_t *node = json_object_get(value, "path");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "domain");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".domain");
          }
          value = node;
          json_t *node = json_object_get(value, "domain");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "expires");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".expires");
          }
          value = node;
          json_t *node = json_object_get(value, "expires");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "httpOnly");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".httpOnly");
          }
          value = node;
          json_t *node = json_object_get(value, "httpOnly");
          if(node) {
            set_integer(json_integer_value(node), module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "secure");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".secure");
          }
          value = node;
          json_t *node = json_object_get(value, "secure");
          if(node) {
            set_integer(json_integer_value(node), module_object, path);
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
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "headers");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".headers");
      }
      value = node;
      json_t *node = json_object_get(value, "headers");
      if(node) {
      }
      json_array_foreach(node, index, value) {
        size_t pathlen = strlen(path);
        snprintf(path+pathlen, sizeof(path)-pathlen, "[%zu]", index);
        json_t *node = value;
        if(node) {
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "name");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".name");
          }
          value = node;
          json_t *node = json_object_get(value, "name");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "value");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".value");
          }
          value = node;
          json_t *node = json_object_get(value, "value");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
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
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "queryString");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".queryString");
      }
      value = node;
      json_t *node = json_object_get(value, "queryString");
      if(node) {
      }
      json_array_foreach(node, index, value) {
        size_t pathlen = strlen(path);
        snprintf(path+pathlen, sizeof(path)-pathlen, "[%zu]", index);
        json_t *node = value;
        if(node) {
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "name");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".name");
          }
          value = node;
          json_t *node = json_object_get(value, "name");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "value");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".value");
          }
          value = node;
          json_t *node = json_object_get(value, "value");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
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
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "postData");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".postData");
      }
      value = node;
      json_t *node = json_object_get(value, "postData");
      if(node) {
      }
      {
        size_t pathlen = strlen(path);
        if(pathlen == 0) {
          snprintf(path+pathlen, sizeof(path)-pathlen, "mimeType");
        } else {
          snprintf(path+pathlen, sizeof(path)-pathlen, ".mimeType");
        }
        value = node;
        json_t *node = json_object_get(value, "mimeType");
        if(node) {
          str = json_string_value(node);
          if(str) set_string(str, module_object, path);
        }
        path[pathlen] = 0;
      }
      {
        size_t pathlen = strlen(path);
        if(pathlen == 0) {
          snprintf(path+pathlen, sizeof(path)-pathlen, "text");
        } else {
          snprintf(path+pathlen, sizeof(path)-pathlen, ".text");
        }
        value = node;
        json_t *node = json_object_get(value, "text");
        if(node) {
          str = json_string_value(node);
          if(str) set_string(str, module_object, path);
        }
        path[pathlen] = 0;
      }
      {
        size_t pathlen = strlen(path);
        if(pathlen == 0) {
          snprintf(path+pathlen, sizeof(path)-pathlen, "params");
        } else {
          snprintf(path+pathlen, sizeof(path)-pathlen, ".params");
        }
        value = node;
        json_t *node = json_object_get(value, "params");
        if(node) {
        }
        json_array_foreach(node, index, value) {
          size_t pathlen = strlen(path);
          snprintf(path+pathlen, sizeof(path)-pathlen, "[%zu]", index);
          json_t *node = value;
          if(node) {
          }
          {
            size_t pathlen = strlen(path);
            if(pathlen == 0) {
              snprintf(path+pathlen, sizeof(path)-pathlen, "name");
            } else {
              snprintf(path+pathlen, sizeof(path)-pathlen, ".name");
            }
            value = node;
            json_t *node = json_object_get(value, "name");
            if(node) {
              str = json_string_value(node);
              if(str) set_string(str, module_object, path);
            }
            path[pathlen] = 0;
          }
          {
            size_t pathlen = strlen(path);
            if(pathlen == 0) {
              snprintf(path+pathlen, sizeof(path)-pathlen, "value");
            } else {
              snprintf(path+pathlen, sizeof(path)-pathlen, ".value");
            }
            value = node;
            json_t *node = json_object_get(value, "value");
            if(node) {
              str = json_string_value(node);
              if(str) set_string(str, module_object, path);
            }
            path[pathlen] = 0;
          }
          {
            size_t pathlen = strlen(path);
            if(pathlen == 0) {
              snprintf(path+pathlen, sizeof(path)-pathlen, "fileName");
            } else {
              snprintf(path+pathlen, sizeof(path)-pathlen, ".fileName");
            }
            value = node;
            json_t *node = json_object_get(value, "fileName");
            if(node) {
              str = json_string_value(node);
              if(str) set_string(str, module_object, path);
            }
            path[pathlen] = 0;
          }
          {
            size_t pathlen = strlen(path);
            if(pathlen == 0) {
              snprintf(path+pathlen, sizeof(path)-pathlen, "contentType");
            } else {
              snprintf(path+pathlen, sizeof(path)-pathlen, ".contentType");
            }
            value = node;
            json_t *node = json_object_get(value, "contentType");
            if(node) {
              str = json_string_value(node);
              if(str) set_string(str, module_object, path);
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
        snprintf(path+pathlen, sizeof(path)-pathlen, "headersSize");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".headersSize");
      }
      value = node;
      json_t *node = json_object_get(value, "headersSize");
      if(node) {
        set_integer(json_integer_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "bodySize");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".bodySize");
      }
      value = node;
      json_t *node = json_object_get(value, "bodySize");
      if(node) {
        set_integer(json_integer_value(node), module_object, path);
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
      snprintf(path+pathlen, sizeof(path)-pathlen, "response");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".response");
    }
    value = node;
    json_t *node = json_object_get(value, "response");
    if(node) {
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "status");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".status");
      }
      value = node;
      json_t *node = json_object_get(value, "status");
      if(node) {
        set_integer(json_integer_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "statusText");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".statusText");
      }
      value = node;
      json_t *node = json_object_get(value, "statusText");
      if(node) {
        str = json_string_value(node);
        if(str) set_string(str, module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "httpVersion");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".httpVersion");
      }
      value = node;
      json_t *node = json_object_get(value, "httpVersion");
      if(node) {
        str = json_string_value(node);
        if(str) set_string(str, module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "cookies");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".cookies");
      }
      value = node;
      json_t *node = json_object_get(value, "cookies");
      if(node) {
      }
      json_array_foreach(node, index, value) {
        size_t pathlen = strlen(path);
        snprintf(path+pathlen, sizeof(path)-pathlen, "[%zu]", index);
        json_t *node = value;
        if(node) {
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "name");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".name");
          }
          value = node;
          json_t *node = json_object_get(value, "name");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "value");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".value");
          }
          value = node;
          json_t *node = json_object_get(value, "value");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "path");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".path");
          }
          value = node;
          json_t *node = json_object_get(value, "path");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "domain");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".domain");
          }
          value = node;
          json_t *node = json_object_get(value, "domain");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "expires");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".expires");
          }
          value = node;
          json_t *node = json_object_get(value, "expires");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "httpOnly");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".httpOnly");
          }
          value = node;
          json_t *node = json_object_get(value, "httpOnly");
          if(node) {
            set_integer(json_integer_value(node), module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "secure");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".secure");
          }
          value = node;
          json_t *node = json_object_get(value, "secure");
          if(node) {
            set_integer(json_integer_value(node), module_object, path);
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
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "headers");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".headers");
      }
      value = node;
      json_t *node = json_object_get(value, "headers");
      if(node) {
      }
      json_array_foreach(node, index, value) {
        size_t pathlen = strlen(path);
        snprintf(path+pathlen, sizeof(path)-pathlen, "[%zu]", index);
        json_t *node = value;
        if(node) {
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "name");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".name");
          }
          value = node;
          json_t *node = json_object_get(value, "name");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
          }
          path[pathlen] = 0;
        }
        {
          size_t pathlen = strlen(path);
          if(pathlen == 0) {
            snprintf(path+pathlen, sizeof(path)-pathlen, "value");
          } else {
            snprintf(path+pathlen, sizeof(path)-pathlen, ".value");
          }
          value = node;
          json_t *node = json_object_get(value, "value");
          if(node) {
            str = json_string_value(node);
            if(str) set_string(str, module_object, path);
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
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "content");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".content");
      }
      value = node;
      json_t *node = json_object_get(value, "content");
      if(node) {
      }
      {
        size_t pathlen = strlen(path);
        if(pathlen == 0) {
          snprintf(path+pathlen, sizeof(path)-pathlen, "size");
        } else {
          snprintf(path+pathlen, sizeof(path)-pathlen, ".size");
        }
        value = node;
        json_t *node = json_object_get(value, "size");
        if(node) {
          set_integer(json_integer_value(node), module_object, path);
        }
        path[pathlen] = 0;
      }
      {
        size_t pathlen = strlen(path);
        if(pathlen == 0) {
          snprintf(path+pathlen, sizeof(path)-pathlen, "compression");
        } else {
          snprintf(path+pathlen, sizeof(path)-pathlen, ".compression");
        }
        value = node;
        json_t *node = json_object_get(value, "compression");
        if(node) {
          set_integer(json_integer_value(node), module_object, path);
        }
        path[pathlen] = 0;
      }
      {
        size_t pathlen = strlen(path);
        if(pathlen == 0) {
          snprintf(path+pathlen, sizeof(path)-pathlen, "mimeType");
        } else {
          snprintf(path+pathlen, sizeof(path)-pathlen, ".mimeType");
        }
        value = node;
        json_t *node = json_object_get(value, "mimeType");
        if(node) {
          str = json_string_value(node);
          if(str) set_string(str, module_object, path);
        }
        path[pathlen] = 0;
      }
      {
        size_t pathlen = strlen(path);
        if(pathlen == 0) {
          snprintf(path+pathlen, sizeof(path)-pathlen, "text");
        } else {
          snprintf(path+pathlen, sizeof(path)-pathlen, ".text");
        }
        value = node;
        json_t *node = json_object_get(value, "text");
        if(node) {
          str = json_string_value(node);
          if(str) set_string(str, module_object, path);
        }
        path[pathlen] = 0;
      }
      {
        size_t pathlen = strlen(path);
        if(pathlen == 0) {
          snprintf(path+pathlen, sizeof(path)-pathlen, "encoding");
        } else {
          snprintf(path+pathlen, sizeof(path)-pathlen, ".encoding");
        }
        value = node;
        json_t *node = json_object_get(value, "encoding");
        if(node) {
          str = json_string_value(node);
          if(str) set_string(str, module_object, path);
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
        snprintf(path+pathlen, sizeof(path)-pathlen, "redirectURL");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".redirectURL");
      }
      value = node;
      json_t *node = json_object_get(value, "redirectURL");
      if(node) {
        str = json_string_value(node);
        if(str) set_string(str, module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "headersSize");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".headersSize");
      }
      value = node;
      json_t *node = json_object_get(value, "headersSize");
      if(node) {
        set_integer(json_integer_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "bodySize");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".bodySize");
      }
      value = node;
      json_t *node = json_object_get(value, "bodySize");
      if(node) {
        set_integer(json_integer_value(node), module_object, path);
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
      snprintf(path+pathlen, sizeof(path)-pathlen, "cache");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".cache");
    }
    value = node;
    json_t *node = json_object_get(value, "cache");
    if(node) {
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "beforeRequest");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".beforeRequest");
      }
      value = node;
      json_t *node = json_object_get(value, "beforeRequest");
      if(node) {
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "afterRequest");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".afterRequest");
      }
      value = node;
      json_t *node = json_object_get(value, "afterRequest");
      if(node) {
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
      snprintf(path+pathlen, sizeof(path)-pathlen, "timings");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".timings");
    }
    value = node;
    json_t *node = json_object_get(value, "timings");
    if(node) {
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "dns");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".dns");
      }
      value = node;
      json_t *node = json_object_get(value, "dns");
      if(node) {
        set_float(json_real_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "connect");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".connect");
      }
      value = node;
      json_t *node = json_object_get(value, "connect");
      if(node) {
        set_float(json_real_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "blocked");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".blocked");
      }
      value = node;
      json_t *node = json_object_get(value, "blocked");
      if(node) {
        set_float(json_real_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "send");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".send");
      }
      value = node;
      json_t *node = json_object_get(value, "send");
      if(node) {
        set_float(json_real_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "wait");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".wait");
      }
      value = node;
      json_t *node = json_object_get(value, "wait");
      if(node) {
        set_float(json_real_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "receive");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".receive");
      }
      value = node;
      json_t *node = json_object_get(value, "receive");
      if(node) {
        set_float(json_real_value(node), module_object, path);
      }
      path[pathlen] = 0;
    }
    {
      size_t pathlen = strlen(path);
      if(pathlen == 0) {
        snprintf(path+pathlen, sizeof(path)-pathlen, "ssl");
      } else {
        snprintf(path+pathlen, sizeof(path)-pathlen, ".ssl");
      }
      value = node;
      json_t *node = json_object_get(value, "ssl");
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
      snprintf(path+pathlen, sizeof(path)-pathlen, "serverIPAddress");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".serverIPAddress");
    }
    value = node;
    json_t *node = json_object_get(value, "serverIPAddress");
    if(node) {
      str = json_string_value(node);
      if(str) set_string(str, module_object, path);
    }
    path[pathlen] = 0;
  }
  {
    size_t pathlen = strlen(path);
    if(pathlen == 0) {
      snprintf(path+pathlen, sizeof(path)-pathlen, "connection");
    } else {
      snprintf(path+pathlen, sizeof(path)-pathlen, ".connection");
    }
    value = node;
    json_t *node = json_object_get(value, "connection");
    if(node) {
      str = json_string_value(node);
      if(str) set_string(str, module_object, path);
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
