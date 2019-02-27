# run

```shell

testodboptimistic --user root --password 5Edidada --database odb_test --host 60.205.225.118
version after persist: 1
process 1 version after load: 1
process 2 version after load: 1
process 1 version after update: 2
process 2 version is out of date: 1
process 2 version after reload: 2
process 2 version after update: 3
final age value: 21
process 1 version is out of date: 2
process 1 version after reload: 3
object not deleted

```
