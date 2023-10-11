#!/bin/bash

url="$1"
message="$2"

git init
echo "After init"

git add .
echo "After add"

git commit -m "$message"
echo "After commit"

git remote add github "$url"
echo "Added remote"

git branch -M main
echo "Branch created"

git push -u github main
echo "After push"



