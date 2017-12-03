reset
rm -f out/app.out
cd src
gcc app.c -o app.out
if [ $? -eq 0 ]; then
    mv app.out ../out/app.out
    cd ../out
    ./app.out
else
    rm -f app.out
    cd ..
fi

echo [END]
