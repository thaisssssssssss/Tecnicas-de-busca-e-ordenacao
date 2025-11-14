ALGORITHMS=("merge" "merge_cutoff" "merge_skip" "merge_cutoff_skip" "merge_bottom-up" "merge_bottom-up_optimized" "merge_bottom-up_optimized-skip")

SIZES=("100000" "1000000")
TYPES=("unif_rand" "sorted" "reverse_sorted" "nearly_sorted")

OUTPUT="resultados.txt"

# Arrays associativos para acumular tempos totais e contar execuções
declare -A tempos_acumulados
declare -A contagem_execucoes
declare -A tempos_por_tamanho  # Formato: "algo_tamanho"
declare -A contagem_por_tamanho

# Inicializa os arrays
for algo in "${ALGORITHMS[@]}"; do
    tempos_acumulados[$algo]="0"
    contagem_execucoes[$algo]=0
    
    for size in "${SIZES[@]}"; do
        tempos_por_tamanho["${algo}_${size}"]="0"
        contagem_por_tamanho["${algo}_${size}"]=0
    done
done

echo "Iniciando testes..." > $OUTPUT
echo "" >> $OUTPUT

for type in "${TYPES[@]}" ; do
    echo +------------------------------------------------------------+ | tee -a $OUTPUT
    echo "Teste $type" | tee -a $OUTPUT

    for i in "${!SIZES[@]}" ;  do
        size="${SIZES[$i]}"
        input_file="input/${type}/${size}.txt"

        # Verifica se o arquivo existe
        if [ ! -f "$input_file" ]; then
            echo "Arquivo não encontrado: $input_file" | tee -a $OUTPUT
            continue
        fi

        echo "" | tee -a $OUTPUT
        echo "Tamanho: $size elementos" | tee -a $OUTPUT

        primeiroTeste=1
        totalTempo=0

        for algo in "${ALGORITHMS[@]}"; do
            echo "  $algo: " | tee -a $OUTPUT
            
            # Captura o tempo
            tempo=$(./$algo $size < $input_file | awk '{print $1}')
            echo "    Tempo: $tempo seconds" | tee -a $OUTPUT
            
            # Acumula tempo para média geral
            tempos_acumulados[$algo]=$(echo "${tempos_acumulados[$algo]} + $tempo" | bc -l)
            contagem_execucoes[$algo]=$((contagem_execucoes[$algo] + 1))
            
            # Acumula tempo por tamanho
            chave="${algo}_${size}"
            tempos_por_tamanho[$chave]=$(echo "${tempos_por_tamanho[$chave]} + $tempo" | bc -l)
            contagem_por_tamanho[$chave]=$((contagem_por_tamanho[$chave] + 1))

            if [ $primeiroTeste -eq 1 ]; then
                maiorTempo=$tempo
                menorTempo=$tempo
                maiorAlgo=$algo
                menorAlgo=$algo
                primeiroTeste=0
            else
                if [ $(echo "$tempo > $maiorTempo" | bc) -eq 1 ]; then
                    maiorTempo=$tempo
                    maiorAlgo=$algo
                fi

                if [ $(echo "$tempo < $menorTempo" | bc) -eq 1 ]; then
                    menorTempo=$tempo
                    menorAlgo=$algo
                fi
            fi

            totalTempo=$(echo "$totalTempo + $tempo" | bc -l)
            echo "" | tee -a $OUTPUT
        done

        qtd=${#ALGORITHMS[@]}
        mediaTempo=$(echo "scale=6; $totalTempo / $qtd" | bc -l)

        echo "  Menor tempo: $menorAlgo ($menorTempo secs)" | tee -a $OUTPUT
        echo "  Maior tempo: $maiorAlgo ($maiorTempo secs)" | tee -a $OUTPUT
        echo "  Média de tempo: $mediaTempo secs" | tee -a $OUTPUT
        echo +------------------------------------------------------------+ | tee -a $OUTPUT
    done
    echo ""
    echo "" >> $OUTPUT
    echo "" >> $OUTPUT
done

# ============================================================
# RESUMO GERAL
# ============================================================

echo "" | tee -a $OUTPUT
echo ============================================================== | tee -a $OUTPUT
echo "RESUMO GERAL - Média de todos os testes" | tee -a $OUTPUT
echo ============================================================== | tee -a $OUTPUT
echo "" | tee -a $OUTPUT

melhorMedia=""
piorMedia=""
melhorAlgo=""
piorAlgo=""
primeiro=1

for algo in "${ALGORITHMS[@]}"; do
    if [ ${contagem_execucoes[$algo]} -gt 0 ]; then
        media=$(echo "scale=6; ${tempos_acumulados[$algo]} / ${contagem_execucoes[$algo]}" | bc -l)
        echo "$algo: $media seconds (média de ${contagem_execucoes[$algo]} execuções)" | tee -a $OUTPUT
        
        if [ $primeiro -eq 1 ]; then
            melhorMedia=$media
            piorMedia=$media
            melhorAlgo=$algo
            piorAlgo=$algo
            primeiro=0
        else
            if [ $(echo "$media < $melhorMedia" | bc) -eq 1 ]; then
                melhorMedia=$media
                melhorAlgo=$algo
            fi
            
            if [ $(echo "$media > $piorMedia" | bc) -eq 1 ]; then
                piorMedia=$media
                piorAlgo=$algo
            fi
        fi
    fi
done

echo "" | tee -a $OUTPUT
echo "👍 MELHOR ALGORITMO (média geral): $melhorAlgo ($melhorMedia secs)" | tee -a $OUTPUT
echo "👎 PIOR ALGORITMO (média geral): $piorAlgo ($piorMedia secs)" | tee -a $OUTPUT
echo "" | tee -a $OUTPUT

# ============================================================
# RESUMO POR TAMANHO DE ENTRADA
# ============================================================

for size in "${SIZES[@]}"; do
    echo "" | tee -a $OUTPUT
    echo ============================================================== | tee -a $OUTPUT
    echo "RESUMO - Tamanho de entrada: $size elementos" | tee -a $OUTPUT
    echo ============================================================== | tee -a $OUTPUT
    echo "" | tee -a $OUTPUT
    
    melhorMedia_size=""
    piorMedia_size=""
    melhorAlgo_size=""
    piorAlgo_size=""
    primeiro_size=1
    
    for algo in "${ALGORITHMS[@]}"; do
        chave="${algo}_${size}"
        if [ ${contagem_por_tamanho[$chave]} -gt 0 ]; then
            media=$(echo "scale=6; ${tempos_por_tamanho[$chave]} / ${contagem_por_tamanho[$chave]}" | bc -l)
            echo "$algo: $media seconds (média de ${contagem_por_tamanho[$chave]} execuções)" | tee -a $OUTPUT
            
            if [ $primeiro_size -eq 1 ]; then
                melhorMedia_size=$media
                piorMedia_size=$media
                melhorAlgo_size=$algo
                piorAlgo_size=$algo
                primeiro_size=0
            else
                if [ $(echo "$media < $melhorMedia_size" | bc) -eq 1 ]; then
                    melhorMedia_size=$media
                    melhorAlgo_size=$algo
                fi
                
                if [ $(echo "$media > $piorMedia_size" | bc) -eq 1 ]; then
                    piorMedia_size=$media
                    piorAlgo_size=$algo
                fi
            fi
        fi
    done
    
    echo "" | tee -a $OUTPUT
    echo "👍 MELHOR para $size elementos: $melhorAlgo_size ($melhorMedia_size secs)" | tee -a $OUTPUT
    echo "👎 PIOR para $size elementos: $piorAlgo_size ($piorMedia_size secs)" | tee -a $OUTPUT
done

echo "" | tee -a $OUTPUT
echo "Testes concluídos! Resultados salvos em $OUTPUT"