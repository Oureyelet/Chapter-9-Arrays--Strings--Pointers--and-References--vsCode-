if you need c++17:

first of all  have to change setting in vsCode for c++17 then:

Add "-std=c++11", "-std=c++17",  to the "args" value in your task.json file.
also in settings.json: 
"cpp": "cd $dir && g++ -std=c++17 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",