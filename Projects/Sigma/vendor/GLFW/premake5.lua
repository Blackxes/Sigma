os.execute("cmake -S . -B build")
os.execute("cmake --build build --config Debug")
os.execute("cmake --build build --config Release")