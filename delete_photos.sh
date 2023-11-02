#!/bin/bash

if [ -d "attachments" ]; then
    rm attachments/*

    rmdir attachments
    
    echo "Ранее загруженные изображения удалены."
else
    echo "Директория 'attachments' не существует или уже пуста."
fi