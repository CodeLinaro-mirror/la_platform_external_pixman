load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_license//rules:license.bzl", "license")
load(":register_tests.bzl", "register_pixman_tests")

package(
    default_applicable_licenses = [":license"],
)

license(
    name = "license",
    package_name = "pixman",
    copyright_notice = "Copyright 1987, 1988, 1989, 1998  The Open Group",
    license_kinds = ["@rules_license//licenses/spdx:MIT"],
    license_text = "COPYING",
    package_url = "https://www.pixman.org/",
    visibility = ["//visibility:public"],
)

exports_files(["COPYING"])

config_setting(
    name = "linux_aarch64",
    constraint_values = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
    ],
)

config_setting(
    name = "linux_x86_64",
    constraint_values = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
)

config_setting(
    name = "windows_aarch64",
    constraint_values = [
        "@platforms//cpu:aarch64",
        "@platforms//os:windows",
    ],
)

config_setting(
    name = "windows_x86_64",
    constraint_values = [
        "@platforms//cpu:x86_64",
        "@platforms//os:windows",
    ],
)

cc_library(
    name = "pixman_asm_aarch64",
    srcs = [
        "pixman/pixman-arma64-neon-asm.S",
        "pixman/pixman-arma64-neon-asm-bilinear.S",
    ],
    hdrs = [
        "os/windows_arm64/pixman/pixman-config.h",
        "pixman/pixman-arm-asm.h",
        "pixman/pixman-arm-common.h",
        "pixman/pixman-arma64-neon-asm.h",
        "pixman/pixman-private.h",
    ],
    copts = [
        "-DHAVE_CONFIG_H",
        "-D__ASSEMBLER__",
        "-DPIXMAN_API=__declspec(dllimport)",
    ],
    includes = [
        "os/windows_arm64/pixman",
        "pixman",
    ],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "pixman_simd",
    srcs = [
        "pixman/pixman-combine32.h",
        "pixman/pixman-compiler.h",
        "pixman/pixman-inlines.h",
    ] + select(
        {
            ":linux_x86_64": [
                "pixman/pixman-mmx.c",
                "pixman/pixman-sse2.c",
                "pixman/pixman-ssse3.c",
            ],
            ":linux_aarch64": [
                "pixman/pixman-arm-asm.h",
                "pixman/pixman-arm-common.h",
                "pixman/pixman-arm-neon.c",
                "pixman/pixman-arma64-neon-asm.S",
                "pixman/pixman-arma64-neon-asm.h",
                "pixman/pixman-arma64-neon-asm-bilinear.S",
            ],
            ":windows_x86_64": [
                "pixman/pixman-mmx.c",
                "pixman/pixman-sse2.c",
                "pixman/pixman-ssse3.c",
            ],
            ":windows_aarch64": [
                "pixman/pixman-arm-asm.h",
                "pixman/pixman-arm-common.h",
                "pixman/pixman-arm-neon.c",
            ],
            "@platforms//os:macos": [
                "pixman/pixman-arm-asm.h",
                "pixman/pixman-arm-common.h",
                "pixman/pixman-arm-neon.c",
                "pixman/pixman-arma64-neon-asm.S",
                "pixman/pixman-arma64-neon-asm.h",
                "pixman/pixman-arma64-neon-asm-bilinear.S",
            ],
            "//conditions:default": [],
        },
    ),
    hdrs = [
        "pixman/pixman.h",
        "pixman/pixman-private.h",
    ] + select(
        {
            "@platforms//os:linux": [
                "os/linux/pixman/pixman-config.h",
                "os/linux/pixman/pixman-version.h",
            ],
            ":windows_x86_64": [
                "os/windows/pixman/pixman-config.h",
                "os/windows/pixman/pixman-version.h",
            ],
            ":windows_aarch64": [
                "os/windows_arm64/pixman/pixman-config.h",
                "os/windows_arm64/pixman/pixman-version.h",
            ],
            "@platforms//os:macos": [
                "os/darwin/pixman/pixman-config.h",
                "os/darwin/pixman/pixman-version.h",
            ],
            "//conditions:default": [],
        },
    ),
    copts = [
        "-DHAVE_CONFIG_H",
    ] + select(
        {
            ":linux_x86_64": [
                "-mssse3",
                "-Wno-macro-redefined",
            ],
            ":linux_aarch64": [
                "-Wno-macro-redefined",
            ],
            ":windows_x86_64": [
                "-mssse3",
                "-DPIXMAN_API=__declspec(dllexport)",
            ],
            ":windows_aarch64": [
                "-DPIXMAN_API=__declspec(dllexport)",
            ],
            "@platforms//os:macos": [
            ],
            "//conditions:default": [],
        },
    ),
    includes = select(
        {
            "@platforms//os:linux": [
                "os/linux/pixman",
            ],
            ":windows_x86_64": [
                "os/windows/pixman",
            ],
            ":windows_aarch64": [
                "os/windows_arm64/pixman",
            ],
            "@platforms//os:macos": [
                "os/darwin/pixman",
            ],
            "//conditions:default": [],
        },
    ),
    visibility = ["//visibility:public"],
    deps = select({
        ":windows_aarch64": [":pixman_asm_aarch64"],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "pixman-1",
    srcs = [
        "pixman/dither/blue-noise-64x64.h",
        "pixman/loongson-mmintrin.h",
        "pixman/pixman.c",
        "pixman/pixman-access.c",
        "pixman/pixman-access-accessors.c",
        "pixman/pixman-arm.c",
        "pixman/pixman-bits-image.c",
        "pixman/pixman-combine-float.c",
        "pixman/pixman-combine32.c",
        "pixman/pixman-conical-gradient.c",
        "pixman/pixman-edge.c",
        "pixman/pixman-edge-accessors.c",
        "pixman/pixman-fast-path.c",
        "pixman/pixman-filter.c",
        "pixman/pixman-general.c",
        "pixman/pixman-glyph.c",
        "pixman/pixman-gradient-walker.c",
        "pixman/pixman-image.c",
        "pixman/pixman-implementation.c",
        "pixman/pixman-linear-gradient.c",
        "pixman/pixman-matrix.c",
        "pixman/pixman-mips.c",
        "pixman/pixman-noop.c",
        "pixman/pixman-ppc.c",
        "pixman/pixman-radial-gradient.c",
        "pixman/pixman-region16.c",
        "pixman/pixman-region32.c",
        "pixman/pixman-solid-fill.c",
        "pixman/pixman-timer.c",
        "pixman/pixman-trap.c",
        "pixman/pixman-utils.c",
        "pixman/pixman-x86.c",
    ],
    hdrs = [
        "pixman/config.h",
        "pixman/pixman.h",
        "pixman/pixman-access.c",
        "pixman/pixman-accessor.h",
        "pixman/pixman-combine32.h",
        "pixman/pixman-compiler.h",
        "pixman/pixman-edge.c",
        "pixman/pixman-edge-imp.h",
        "pixman/pixman-inlines.h",
        "pixman/pixman-private.h",
        "pixman/pixman-region.c",
    ] + select(
        {
            "@platforms//os:linux": [
                "os/linux/pixman/pixman-config.h",
                "os/linux/pixman/pixman-version.h",
            ],
            ":windows_x86_64": [
                "os/windows/pixman/pixman-config.h",
                "os/windows/pixman/pixman-version.h",
            ],
            ":windows_aarch64": [
                "os/windows_arm64/pixman/pixman-config.h",
                "os/windows_arm64/pixman/pixman-version.h",
            ],
            "@platforms//os:macos": [
                "os/darwin/pixman/pixman-config.h",
                "os/darwin/pixman/pixman-version.h",
            ],
            "//conditions:default": [],
        },
    ),
    copts = [
        "-Wno-unused-const-variable",
        "-Wno-unused-local-typedefs",
        "-Wno-expansion-to-defined",
        "-DHAVE_CONFIG_H",
    ],
    includes = ["pixman"] + select(
        {
            "@platforms//os:linux": [
                "os/linux/pixman",
            ],
            ":windows_x86_64": [
                "os/windows/pixman",
            ],
            ":windows_aarch64": [
                "os/windows_arm64/pixman",
            ],
            "@platforms//os:macos": [
                "os/darwin/pixman",
            ],
            "//conditions:default": [],
        },
    ),
    visibility = ["//visibility:public"],
    deps = [":pixman_simd"],
)

# Basic utils independet of libpng.
cc_library(
    name = "pixman-test-utils",
    srcs = [
        "pixman/config.h",
        "test/utils.c",
        "test/utils.h",
        "test/utils-prng.c",
        "test/utils-prng.h",
    ],
    copts = [
        "-DHAVE_CONFIG_H",
        "-Wno-switch",
    ],
    includes = ["test"],
    deps = [":pixman-1"],
)

# Commented out ones need png version of utils, which we do not yet have
register_pixman_tests(tests = [
    "a1-trap-test",
    "alpha-loop",
    "combiner-test",
    # "composite", # Too slow..
    "fence-image-self-test",
    "fetch-test",
    "filter-reduction-test",
    "glyph-test",
    "gradient-crash-test",
    "infinite-loop",
    "matrix-test",
    "oob-test",
    "pdf-op-test",
    "pixel-test",
    "prng-test",
    "region-contains-test",
    "region-test",
    "region-translate-test",
    "rotate-test",
    "scaling-crash-test",
    "scaling-helpers-test",
    "trap-crasher",
    # "affine-test",
    # "alphamap",
    # "blitters-test",
    # "composite-traps-test",
    # "cover-test",
    # "radial-invalid",
    # "scaling-test",
    # "solid-test",
    # "stress-test",
    # "tolerance-test", # Needs png
])
