MAGENTA="\033[0;35m"
CYAN="\033[0;36m"
RESET="\033[0m"

echo ${CYAN}"========================"
echo "Testing char conversions"
echo "========================"${RESET}

echo ${MAGENTA}"input: ' '"${RESET}
./converter ' '

echo ${CYAN}"\n========================"
echo "Testing int conversions"
echo "========================"${RESET}

echo ${MAGENTA}"\ninput: \"42\""${RESET}
./converter "42"
echo ${MAGENTA}"\ninput: \"-42\""${RESET}
./converter "-42"
echo ${MAGENTA}"\ninput: \"+42\""${RESET}
./converter "+42"
echo ${MAGENTA}"\ninput: \"4\""${RESET}
./converter "4";
echo ${MAGENTA}"\ninput: \"-4\""${RESET}
./converter "-4";
echo ${MAGENTA}"\ninput: \"+4\""${RESET}
./converter "+4";
echo ${MAGENTA}"\ninput: \"2147483648\""${RESET}
./converter "2147483648"

echo ${CYAN}"\n========================"
echo "Testing float conversions"
echo "========================"${RESET}

echo ${MAGENTA}"\ninput: \"3.14f\""${RESET}
./converter "3.14f"
echo ${MAGENTA}"\ninput: \"-3.14f\""${RESET}
./converter "-3.14f"
echo ${MAGENTA}"\ninput: \"+3.14f\""${RESET}
./converter "+3.14f"
echo ${MAGENTA}"\ninput: \"3.0f\""${RESET}
./converter "3.0f"
echo ${MAGENTA}"\ninput: \"3.f\""${RESET}
./converter "3.f"
echo ${MAGENTA}"\ninput: \"-inff\""${RESET}
./converter "-inff"
echo ${MAGENTA}"\ninput: \"+inff\""${RESET}
./converter "+inff"
echo ${MAGENTA}"\ninput: \"nanf\""${RESET}
./converter "nanf"

echo ${CYAN}"\n========================"
echo "Testing double conversions"
echo "========================"${RESET}

echo ${MAGENTA}"\ninput: \"0.3\""${RESET}
./converter "0.3"
echo ${MAGENTA}"\ninput: \"-0.3\""${RESET}
./converter "-0.3"
echo ${MAGENTA}"\ninput: \"+0.3\""${RESET}
./converter "+0.3"
echo ${MAGENTA}"\ninput: \"0.0\""${RESET}
./converter "0.0"
echo ${MAGENTA}"\ninput: \"0.\""${RESET}
./converter "0."
echo ${MAGENTA}"\ninput: \"-inf\""${RESET}
./converter "-inf"
echo ${MAGENTA}"\ninput: \"+inf\""${RESET}
./converter "+inf"
echo ${MAGENTA}"\ninput: \"nan\""${RESET}
./converter "nan"