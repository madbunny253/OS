#!/bin/bash

while true
do
	echo -e "1.Create\n2.Open\n3.Display\n4.Insert\n5.Modify\n6.Delete\n7.Exit"
	read ch
	case $ch in
		1)
			echo "Enter"
			read fname
			touch $fname
			echo -e "\n$fname created"
			;;
		2)
			fname="f.txt"
			echo -e "\n$fname OPENED"
			;;
		3)	
			cat $fname
			;;
		4)	
			cont=1
			while [ $cont -eq 1 ]
			do			
				echo "ENter ID:"
				read id
				echo "ENter name:"
				read name
				echo "ENter city:"
				read city
				echo -e "$id\t$name\t$city" >> $fname
				echo "1.Cont	2.Not COn"
				read cont
			done
			;;
		5)
			echo "enter to modify"
			read oldname
			echo "enter new"
			read newname
			sed -i s/$oldname/$newname/g $fname
			;;
		6)	
			echo "enter to delet"
			read delname
			grep -v $delname $fname >> temp.txt
			rm $fname
			mv temp.txt $fname
			;;
		7)
			exit
			;;
		*)
			echo "Invalid"
	esac
done
