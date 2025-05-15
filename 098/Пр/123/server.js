import express from 'express';
import fs from 'fs';
import path from 'path';
import { fileURLToPath } from 'url';

const app = express();
const port = 3000;

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

app.use(express.static('public'));
app.use(express.text({ type: 'text/*' }));

const DATA_DIR = path.join(__dirname, 'data');
const WRITE_FILENAME = 'text.txt';
const WRITE_FILENAME2 = 'text2.txt';

app.post('/save/:filename', (req, res) => {
  const filepath = path.join(DATA_DIR, WRITE_FILENAME);
  const data = req.body;

  fs.writeFile(filepath, data, (err) => {
    if (err) {
      console.error(err);
      return res.status(500).send('Ошибка при сохранении файла.');
    }
    res.send('Файл успешно сохранен!');
  });
});

app.post('/save2/:filename', (req, res) => {
  const filepath = path.join(DATA_DIR, WRITE_FILENAME2);
  const data = req.body;

  fs.writeFile(filepath, data, (err) => {
    if (err) {
      console.error(err);
      return res.status(500).send('Ошибка при сохранении файла.');
    }
    res.send('Файл успешно сохранен!');
  });
});

app.get('/load', (req, res) => {
  const filename = req.query.filename;

    if (!filename) {
        return res.status(400).send('Не указан параметр filename.');
    }

  const filepath = path.join(DATA_DIR, filename);

  fs.readFile(filepath, 'utf8', (err, data) => {
    if (err) {
      console.error(err);
      return res.status(404).send(`Файл ${filename} не найден.`);
    }
    res.send(data);
  });
});

app.listen(port, () => {
  console.log(`Сервер запущен на порту ${port}`);
});