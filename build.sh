#!/usr/bin/env bash

cd android
rm -rf app/.externalNativeBuild

./gradlew clean

./gradlew build

