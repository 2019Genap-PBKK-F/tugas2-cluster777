//Load HTTP module
  
const express = require("express");
const app = express();
const sql = require('mssql')
hostname='127.0.0.1'
//const hostname = '10.199.14.46';
const port = 8009;

//cors
app.use(function (req, res, next) {
  //Enabling CORS 
  res.header("Access-Control-Allow-Origin", "*");
  next();
});

var bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json())

const config = {
    user: 'su',
    password: 'SaSa1212',
    server: '10.199.13.253',
    database: 'nrp05111740000045'
};

var executeQuery = function(res, query, param, reqType) {
  sql.connect(config, function(err){
    if(err) {
      res.end('Connection Error\n' + err)
    }
    else {
      var request = new sql.Request()
      if(reqType != 0) {
        param.forEach(function(p)
        {
          request.input(p.name, p.sqltype, p.value);
        });
      }
      request.query(query, function(err, response){
        if(err) {
          console.log('Query Error\n' + err)
        }
        else{
          res.send(response.recordset)
        }
     })
    }
  })
}
app.get("/api/mahasiswa", function(req, res)
{
  
  var query = "select * from mahasiswa";
  executeQuery(res, query, null, 0);
});
app.post("/api/mahasiswa/post", function(req, res)
{
  var param = [
    { name: 'nrp', sqltype: sql.Char, value: req.body.nrp },
    { name: 'nama', sqltype: sql.VarChar, value: req.body.nama }
  ]
app.put()
  var query = 'insert into mahasiswa ( nrp, nama) values( @nrp, @nama)';
  executeQuery(res, query, param, 1)
})
app.delete('api/mahasiswa/delete/:id', function (req, res) {
    var request = new sql.Request();
    const id = req.params.idDelete;
    console.log(
        'diterima request delete ' + req.params.idDelete
    )
    request.query("Delete From mahasiswa where .id = '"+ id +"'", function (err, recordset) {
        if (err) console.log(err)
        console.log("berhasil Delete dengan id " + id)
        res.send('Berhasil');
    });
  });

app.put('api/mahasiswa/update/:id', function (req, res) {
    sql.connect(config, function (err) {
        if (err) console.log(err);
        var request = new sql.Request();
        request.query("UPDATE mahasiswa set [NRP]='"+req.body.NRP+ "',[NAMA] = '"+req.body.NAMA+"' where mahasiswa.id ="+ req.body.id , function (err, recordset) {
            if (err) console.log(err)
            console.log("berhasil diedit")
            res.send('yeet');
        });
    });
  });
//listen for request on port 3000, and as a callback function have the port listened on logged
app.listen(port, hostname, function () {
  var message = "Server runnning on Port: " + port;
  console.log(message);
});
