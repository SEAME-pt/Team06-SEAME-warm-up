import subprocess
import time
import os

# Função para executar o programa e medir o tempo
def measure_execution_time(executable_path, command, input_string):
    start_time = time.time()
    process = subprocess.Popen([executable_path, command, input_string], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, _ = process.communicate()
    end_time = time.time()
    duration = end_time - start_time
    return output.decode().strip(), duration


def check_executable_exists(executable_path):
    return os.path.isfile(executable_path)

# Função para comparar dois executáveis por múltiplas iterações e calcula a diferença percentual de tempo
def compare_executables_with_iterations(executable1, executable2, command, input_string, expected_output, iterations=10):
    # Verifica se ambos os executáveis existem
    if not check_executable_exists(executable1):
        print(f"Erro: O executável '{executable1}' não foi encontrado.")
        return
    if not check_executable_exists(executable2):
        print(f"Erro: O executável '{executable2}' não foi encontrado.")
        return    
    
    time1_total, time2_total = 0.0, 0.0
    success = True

    for i in range(iterations):
        output1, time1 = measure_execution_time(executable1, command, input_string)
        output2, time2 = measure_execution_time(executable2, command, input_string)

        # Verifica se ambos os executáveis produzem o resultado esperado
        if output1 != expected_output or output2 != expected_output:
            print(f"Falha na iteração {i + 1}:")
            print(f"Executável 1 - Esperado: {expected_output}, Obtido: {output1}")
            print(f"Executável 2 - Esperado: {expected_output}, Obtido: {output2}")
            success = False
            break

        # Acumula o tempo de cada execução
        time1_total += time1
        time2_total += time2

    if success:
        # Calcula o tempo médio de cada executável
        avg_time1 = time1_total / iterations
        avg_time2 = time2_total / iterations

        # Calcula a diferença percentual
        if avg_time1 < avg_time2:
            faster_exec = "Executável 1"
            percentage_diff = ((avg_time2 - avg_time1) / avg_time2) * 100
        else:
            faster_exec = "Executável 2"
            percentage_diff = ((avg_time1 - avg_time2) / avg_time1) * 100

        # Exibe os resultados
        print(f"Tempo médio do Executável 1: {avg_time1:.4f} segundos")
        print(f"Tempo médio do Executável 2: {avg_time2:.4f} segundos")
        print(f"{faster_exec} foi mais rápido por aproximadamente {percentage_diff:.2f}%.")


def main():
    executable1 = "./module00/ex02/convert_v1"
    executable2 = "./module00/ex02/convert_v2"

    compare_executables_with_iterations(executable1, executable2, "up", "Hello World", "HELLO WORLD", iterations=10)

if __name__ == "__main__":
    main()
