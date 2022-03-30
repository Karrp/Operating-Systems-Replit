{ pkgs }: {
	deps = [
		pkgs.clang_12
		pkgs.cmake
		pkgs.gdb
        pkgs.tmux
        pkgs.vim
        pkgs.mc
	];
}