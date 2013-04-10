cc_library(
    name = 'atomic',
    srcs = [
        'atomicops-internals-x86.cc',
    ]
)

cc_library(
    name = 'once',
    srcs = [
        'once.cc',
    ],
    deps = [
        ':atomic',
        ':dynamic_annotations',
    ]
)

cc_library(
    name = 'spinlock',
    srcs = [
        'spinlock_wait.cc'
    ],
    deps = [
        ':atomic',
    ]
)

cc_library(
    name = 'bits',
    srcs = [
        'bits.cc',
    ]
)

cc_library(
    name = 'demangle',
    srcs = [
        'demangle.cc',
    ]
)

cc_library(
    name = 'dynamic_annotations',
    srcs = [
        'dynamic_annotations.c',
    ]
)

cc_library(
    name = 'mathlimits',
    srcs = [
        'mathlimits.cc',
    ]
)

cc_library(
    name = 'random',
    srcs = [
        'random.cc',
    ]
)
