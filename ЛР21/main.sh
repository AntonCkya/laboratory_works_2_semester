#!/bin/bash

IS_HELP=0
EXIT=0
FILE=""
SUFFIX=""
BLOCK_SIZE=$(stat -fc %s .)

while (($#>0)); do
	case "$1" in
		-f|--file)
			FILE=$2
			shift
			shift;;
		-s|--suffix)
			SUFFIX=$2
			shift
			shift;;
		-h|--help)
			IS_HELP=1
			shift;;	
		?*)
			echo "$0: Ошибка в синтаксисе или неправильное использование команды" > /dev/stderr
			exit 1;;
	esac
done

if (($IS_HELP==1)); then
	echo ""
	echo "Программа выводит имена и размеры всех невыполняемых файлов с заданным суффиксом в заданный файл:"
	echo "$0 -s суффикс -f файл"
	echo "Если заданный суффикс не введён - выведет все файлы"
	echo "Если заданный файл не введён - выведет в стандартный вывод"
	echo "Вывод имеет вид: название_файла размер_в_байтах"
	echo ""
	exit 0
fi

if [[ "$FILE" != "" ]]; then
    echo "файл: $FILE"
fi
    
if [[ "$SUFFIX" != "" ]]; then
    echo "суффикс: $SUFFIX"
fi
    
F=""
for file in "$(find . -maxdepth 1 -name  "*${SUFFIX}" -not -executable -ls)"; do
    F+=$(echo "${file}" | awk -v B=$BLOCK_SIZE '{if($7 % B == 0){for(i=11;i<=NF - 1;i++) printf substr($i,1,length($i)-1) " "; print $NF" " $7;}}' | cut -c 3-)
done
if [[ "$FILE" == "" ]]; then
    echo "$F"
else
    echo "$F" >"$FILE"
fi

