#!/bin/bash
mkdir -p attachments
for ((i=1; i<=20; i++))
do
    filename="attachments/photo${i}.jpg"

    curl https://picsum.photos/800/400 -L > "$filename"
done