## Bee Visualization for WbLS 

## Prepare the data

```bash
cd scripts/
root -b -q loadClasses.C 'run.C("/path/to/ratfile.root", eventNo)'
```

This will create a new directory `data/` under the `scripts/` directory with the following structure:
```
data/
├── 0
│   ├── 0-Attenuation.json
│   ├── 0-Cerenkov.json
│   ├── 0-G4FastSimulationManagerProcess.json
│   └── 0-Transportation.json
├── 1
│   ├── 1-Attenuation.json
│   ├── 1-Cerenkov.json
│   ├── 1-G4FastSimulationManagerProcess.json
│   └── 1-Transportation.json
...
```
Any existing files there will be replaced by the new ones, so make sure that you intend to do that.

After you verify all files are produced correctly, move the whole `data/` directory up one level so that the `data` directory is at the same level as `js/` and `scripts/`. Backup any old data, if any, beforehand.

## View the data 

If you're using python2, do:
```bash
python -m SimpleHTTPServer
```

If you're using python3, do:
```bash
python -m http.server
```

Then open a web browser and go to `http://localhost:8000/`

Depending on how many events are under the `data/` directory, you may want to change the `MAX_EVENTS` accordingly at the top of the file `js/wbls.js`. The event numbers must start from 0 and increase continuously.

## Remote Access

The following uses Milind workstation (`mvd`) as the server as an example.

Login mvd with ssh forwarding of localhost:
```bash
ssh -L 8000:localhost:8000 mvd
```
where `mvd` is alias for host, which I've set up in my ~/.ssh/config file on local machine:

```bash
Host mvd
     ForwardAgent yes
     ForwardX11 yes
     ForwardX11Trusted yes
     HostKeyAlias mvd
     Hostname mvd
     PreferredAuthentications publickey
     ProxyCommand ssh -A [username]@physsh.phy.bnl.gov -W %h:%p
     ServerAliveInterval 60
     User [username]
```