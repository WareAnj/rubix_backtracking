reset
rm out/app.out
cd src
gcc app.c -o app.out
if [ $? -eq 0 ]; then
    mv app.out ../out/app.out
    cd ../out
    ./app.out
    echo [OK]
else
    rm app.out
    cd ..
    echo [FAIL]
fi
