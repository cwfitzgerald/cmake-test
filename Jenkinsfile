pipeline {
  agent any
  stages {
    stage('Build') {
      parallel {
        stage('Build-GCC') {
          steps {
            node('gce-worker') {
              sh '''mkdir build
cd build
cmake .. -GNinja
'''
              sh 'ninja'
            }
          }
        }
        stage('Build-Clang') {
          steps {
            node('gce-worker') {
              sh '''mkdir build
cd build
cmake .. -GNinja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
'''
              sh 'ninja'
            }
          }
        }
      }
    }
  }
}
