#!/bin/bash

git add --all
git commit -m "$(date)"
git pull
git push
