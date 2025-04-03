const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "LaPuta",
        .target = target,
        .optimize = optimize,
    });

    const c_files = [_][]const u8{
        "main.c",
    };

    exe.root_module.addCSourceFiles(.{
        .root = b.path("src/"),
        .files = &c_files,
    });

    exe.linkSystemLibrary("SDL3");
    exe.linkSystemLibrary("c");

    b.installArtifact(exe);

    const run_exe = b.addRunArtifact(exe);
    const run_step = b.step("run", "Run the application.");
    run_step.dependOn(&run_exe.step);
}
