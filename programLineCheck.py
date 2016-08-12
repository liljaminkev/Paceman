#!/usr/bin/python3
#This is a program to count the number of lines in the whole project.
import sys
import re
import os
import mimetypes

total = 0

def fileCount(fileName):
	totalLines = 0
	fileObj = open(fileName, 'r')
	startComment = False
	for line in (fileObj):
		line = ''.join(line.split())
		if(len(line) >= 2):
			if((line[0] == '/') and (line[1] == '/')):
				continue
		if(len(line) < 1):
			continue
		if(bool(re.search('/\*.*\*/', line))):
			if(line.startswith('/*') and line.endswith('*/')):
				continue
		elif(bool(re.search('/\*.*', line))):
			startComment = True
			if(line.startswith('/*')):
				continue
		if(bool(re.search('.*\*/*', line))):
			startComment = False
			if(line.endswith('*/')):
				continue
		totalLines += 1
	return totalLines

if(len(sys.argv) != 2):
	print("Provide directory name as argument. '.' if it is current directory.")
	quit()

for root, dirs, files in os.walk(sys.argv[1]):
	tempTotal = 0
	for fileName in files:
		mime = mimetypes.guess_type(fileName)
		if(mime[0] is not None):
			if(mime[0].startswith('text')):
				print("File Name: ", end='')
				print(fileName)
				tempTotal = fileCount(root+'/'+fileName)
				print(tempTotal)
				total += tempTotal


print("Total Lines: ")
print(total)
