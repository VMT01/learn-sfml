if [ -z "$1" ]; then
    echo "No argument detected. Running test!";
    if [ -d "${dir}/resources" ]; then
        script="g++ -g test/resources/*.cpp test/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system"
    else 
        script="g++ -g test/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system"
    fi
else
    script="g++ -g $1/resources/*.cpp $1/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system"
fi

echo "Building: \e[93m${script}\e[0m"
${script}

if [ -r "./main" ]; then
    echo "Building: \e[92mDone\e[0m"
    echo "Running: \e[93mmain\e[0m"
    ./main
    echo "Running: \e[92mDone\e[0m"
fi