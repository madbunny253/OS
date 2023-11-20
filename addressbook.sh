#!/bin/bash
while true
do
	echo -e "\n1. Create Addressbook\n2. Insert record\n3. Display record\n4. Search record\n5. Modify record\n6. Delete Record\n7. Exit\n\nEnter choice"
	read ch
	v=1
	case $ch in
		1)
		  echo -e "\nEnter file name :"
		  read fname
		  touch $fname.txt
		  echo -e "$fname.txt file created successfully."
		  ;;
		2)
		  while [ $v -eq 1 ]
		  do 
		  	echo -e "\nEnter employee's name :"
		  	read name
		  	echo -e "Enter employee number :"
		  	read eno
		  	echo -e "Enter employee's mobile number :"
		  	read mno
		  	echo -e "Enter employee's city :"
		  	read city
		  	echo -e "$name\t$eno\t$mno\t$city" >> $fname.txt
		  	echo -e "Do you want to continue? Press 1 to continue"
		  	read v
		  done
		  ;;
		3)
		  cat emp.txt
		  ;;
		4)
		  echo -e "Enter name that you want to search :"
		  read ename
		  grep $ename $fname.txt
		  ;;
		5)
		  echo -e "Enter name that you want to modify :"
		  read emname
		  echo -e "Enter new name :"
		  read empname
		  sed -i s/$emname/$empname/g $fname.txt
		  ;;
		6)
		  echo -e "Enter name that you want to delete :"
		  read emplname
		  grep -v $emplname $fname.txt >> temp.txt
		  rm $fname.txt
		  mv temp.txt $fname.txt
		  ;;
		7)
		  exit
		  ;;
		*)
	esac
done

