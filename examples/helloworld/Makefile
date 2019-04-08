build: prebuild
	clang-8 src/main.c -S -emit-llvm --target=wasm32 -o tmp/src/main.ll
	clang-8 vendor/stdwasm/stdwasm.c -S -emit-llvm --target=wasm32 -o tmp/vendor/stdwasm/stdwasm.ll
	llvm-link-8 -o tmp/main.bc tmp/src/*\.ll tmp/vendor/stdwasm/*\.ll
	opt-8 -O3 tmp/main.bc -o tmp/main.bc
	llc-8 -mtriple=wasm32-unknown-unknown -O3 -filetype=obj tmp/main.bc -o tmp/main.o
	wasm-ld-8 tmp/main.o -o main.wasm --no-entry --export-dynamic -allow-undefined
	rm -rf tmp
prebuild:
	mkdir -p tmp/src
	mkdir -p tmp/vendor/stdwasm
lint:
	clang-format -i src/main.c
serve: build
	python3 -m http.server
