if [ -z "$1" ]
then
    echo "No argument detected. Running test!";
    dir="test";
    echo "Building: \e[93mg++ -g ${dir}/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system\e[0m"
    g++ -g ${dir}/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
    echo "Building: \e[92mDone\e[0m"
else
    dir=$1
    echo "Building: \e[93mg++ -g ${dir}/resources/*.cpp main.cpp -o ${dir}/main -lsfml-graphics -lsfml-window -lsfml-system\e[0m"
    g++ -g ${dir}/resources/*.cpp ${dir}/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
    echo "Building: \e[92mDone\e[0m"
fi

echo "Running: \e[93mmain\e[0m"
./main
echo "Running: \e[92mDone\e[0m"