pipeline {
  agent {
    label 'master'
  }
  stages {
    stage('Prepare') {
      steps {
        checkout scm
        stash name: 'source', includes: '**/*'
      }
    }
    stage('Build') {
      parallel {
        stage('Build-GCC') {
          steps {
            node('gce-worker') {
              unstash name: 'source'
              sh 'ls -lah'
              sh '''mkdir build
cd build
cmake .. -GNinja
'''
              sh 'cd build; ninja'
            }
          }
        }
        stage('Build-Clang') {
          steps {
            node('gce-worker') {
              unstash name: 'source'
              sh 'ls -lah'
              sh '''mkdir build
cd build
cmake .. -GNinja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
'''
              sh 'cd build; ninja'
            }
          }
        }
      }
    }
  }
}
