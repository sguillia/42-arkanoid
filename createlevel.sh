make -C generator
./generator/arkanoid_generator
cp levels/lvl0 SAVE_lvl0
mv NEWLEVEL levels/lvl0
echo ""
echo ""
#echo "The new level file is: NEWLEVEL"
#echo "Move it to levels/lvlX (with X as a number) to test it !"
