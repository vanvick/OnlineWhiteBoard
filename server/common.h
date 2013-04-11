#undef FORBIDDEN_EVIL_CONSTRUCTORS
#define FORBIDDEN_EVIL_CONSTRUCTORS(TypeName) \
TypeName(const TypeName&); \
void operator=(const TypeName&)