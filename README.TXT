if you need c++17:

Add "-std=c++11", "-std=c++17",  to the "args" value in your task.json file.
also in settings.json: 
"cpp": "cd $dir && g++ -std=c++17 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",