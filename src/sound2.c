//include<dos.h> this won't work in UNIX orry guys im working on it.

main()
{
    int z;
    for (z=300; z<= 1000; z=z + 20 )
{
    sound(z);
    delay(20);

}
nosound(); //used in c Dictonary
return 0;
}
