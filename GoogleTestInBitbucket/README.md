# GoogleTests в bitbucket'e #

Инструкция по использованию Google Tests в bitbucket.

### Шаг 1 ###

Убедитесь, что ваш ```CMakeLists.txt``` файл имеет следующий вид (если вы не используете CMake вам все равно придется добавить CMakeLists.txt в вашу папку с проектом в репозитории):    


```cmake

cmake_minimum_required(VERSION 3.5)
project(task)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 14)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(mytest main.cpp Implementation.cpp Declaration.h) 

target_link_libraries(mytest ${GTEST_LIBRARIES} pthread)
```
```task``` и ```mytest``` - это название проекта и имя исполняемого файла соответственно.
### Шаг 2 ###
Добавьте в корневую папку репозитория файл с именем ```bitbucket-pipelines.yml``` со следующим кодом: 
 
```yml

image: atlassian/default-image:2

pipelines:
  default:
    - step:
        script:
          - apt-get update -y
          - apt-get install -y cmake
          - apt-get install -y libgtest-dev
          - cd /usr/src/gtest
          - cmake .
          - make
          - cp *.a /usr/lib
          - cd /opt/atlassian/pipelines/agent/build/task/
          - cmake .
          - make
          - ./mytest
```
```task``` - название папки, в которой лежат source файлы, ```mytest``` - имя исполняемой программы 


### Шаг 3 ###

Кликните на **Pipelines** в меню репозитория на сайте. Внизу кликните по кнопке **Enable**. 

### Шаг 4 ###

- Теперь в **Pipelines** будет список из доступных пайплайнов (по идее там должен быть один). 
- В графе **Status** должно быть **Successful**. 
- Кликнув по успs
- Кликните по предпоследней команде ```./mytest```
- Поздравляю, теперь вы можете выполнять Google тесты в bitbucket'e!

### Легкий гайд по установке Google Tests на Ubuntu ###
https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
