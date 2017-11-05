#define CAIRO_CHECK(func, ...) { \
  if (auto status_ = func(__VA_ARGS__); status_ != CAIRO_STATUS_SUCCESS) { \
    throw \
      std::runtime_error( \
        #func " failed with error: " \
        + std::string{cairo_status_to_string(status_)}); \
  } \
}

#define CAIRO_CLEANUP_CHECK(cleanup, func, ...) { \
  if (auto status_ = func(__VA_ARGS__); status_ != CAIRO_STATUS_SUCCESS) { \
    cleanup \
    throw \
      std::runtime_error( \
        #func " failed with error: " \
        + std::string{cairo_status_to_string(status_)}); \
  } \
}
