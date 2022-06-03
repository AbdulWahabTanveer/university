import numpy as np 
import os


#List of files found in the subdirectories of the dir you use code in
#this code is intentionaly designed to leave current dir files and files
#with .py extentions
finalfiles = []

#using os to find files dir etc
path = os.walk(".")

#appends finalfiles and adds all files with full path names
for root, directories, files in path:
    for directory in directories:
        for filename in os.listdir(directory):
            f = os.path.join(directory, filename)
            # checking if it is a file
            if os.path.isfile(f):
                finalfiles.append(f)


#set to contain unique words as per described
unique_word_set = set()

#to store number of files that the program has found
file_count = len(finalfiles)

#using nested dictionary to store file contents
#instead of having a separate dic for each file we have one
#which then has nested dic as per required
#i used this method cuz we will get to know at runtime how many dic are required
files_content = {}

#inserts a nested dic for each file with its name as the key
for file in finalfiles:
    files_content[file] = {}


#finding unique words in all files
for file in finalfiles:
    text_file = open(file, 'r')
    text = text_file.read()

    #cleaning and dealing with upper lower case as I kept it case insensitive
    text = text.lower()
    words = text.split()
    words = [word.strip('.,!;()[]') for word in words]
    words = [word.replace("'s", '') for word in words]

    #finding unique words
    for word in words:
        #adding file contents to file nested dictionary
        #instead of using a seperate loop i am adding file contents basically
        #words the file contains in the sub dic i made and initialized earlier
        if word not in files_content[file]:
            files_content[file][word] = 1
        #and also it stores how many times each word is there so there
        #is room for future imporved versions
        else:
            files_content[file][word] = files_content.get(file).get(word) + 1
        #adding unique words in set
        if word not in unique_word_set:
            unique_word_set.add(word)
    #closing file after use important
    text_file.close()

#i needed to find index where the item is as it cannot be done
#on a set so made a copy as a list
unique_word_list = list(unique_word_set)


            #printing as required
print("\nNumber of Files are",file_count,"\n")

print("Unique Words are \n",unique_word_set,"\n")


#creating that matrix as said
matrix = np.zeros((file_count,len(unique_word_set)))

#setting up variables for my logic to insert
#1 in the matrix
i = 0 
j= 0

#logic to handle that tdm
for unique_word in unique_word_set:
    i=0
    for file in finalfiles:
        if unique_word in files_content[file].keys():
            matrix[i][j] = 1
        i+=1
    j+=1

#printing matrix
print("Matrix\n",matrix,"\n\n")

#initializing with vector with zeros
vector_dot = np.zeros((len(unique_word_set),1))

#getting user input
user_input = input("Please enter words to search \n\n")

#handling user input as i have handled unique words 
#so that they can be compared
user_input = user_input.lower()
search_words = user_input.split()
search_words = [word.strip('.,!;()[]') for word in search_words]
search_words = [word.replace("'s", '') for word in search_words]

#inserting 1 on the indexes where input matches the unique words set 
for each_word in search_words:
    if each_word in unique_word_list:
        vector_dot[unique_word_list.index(each_word)][0] = 1

#getting the dot to find resultant
resultant = matrix.dot(vector_dot)

#finding index with highest value
result = np.where(resultant == np.amax(resultant))

#opening file with highest matches
fh = open(finalfiles[result[0][0]],'r')

#printing file with highest matches
print("\nFile with highest matches is ",finalfiles[result[0][0]],"\nFile Contents are\n")
print(fh.read())