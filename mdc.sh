#!/bin/bash

g++ -g -o main main.cpp

sizes=(500 5000 50000 500000)

num_runs=10

results_dir="results_massif"
mkdir -p $results_dir

for size in "${sizes[@]}"; do
    echo "Procesando tamaño: $size"

    # Bucle para repetir cada tamaño de datos $num_runs veces
    for ((run=1; run<=num_runs; run++)); do
        echo "  Ejecución $run de $num_runs para tamaño $size"

        # Ejecutar valgrind
        valgrind --tool=massif --massif-out-file=massif.out ./main $size

        # Guardar el resultado
        ms_print massif.out > $results_dir/massif_${size}_run${run}.txt
    done
done

echo "Mediciones completadas. Resultados guardados en $results_dir"