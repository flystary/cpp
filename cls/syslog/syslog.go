package main

import (
	"fmt"
	"os"
	"strings"
	"time"
)

type Line struct {
    date    string
    time    string
    mode    string
    action  string
    in      string
    out     string
    src     string
    dst     string
    proto   string
    ltype   string
    code    string
    spt     string
    dpt     string
}

func init() {
    mkdirs()
}

func mkdirs() {
    root := "/var/log/firewall"
    CreateMutiDir(root)

}

type Log interface {
    write()
}


func CreateMutiDir(filePath string) error {
	if !isExist(filePath) {
		err := os.MkdirAll(filePath, os.ModePerm)
		if err != nil {
			// fmt.Println("创建文件夹失败,error info:", err)
			return err
		}
		return err
	}
	return nil
}

func isExist(path string) bool {
	_, err := os.Stat(path) //os.Stat获取文件信息
	if err != nil {
        return os.IsExist(err)
	}
	return true
}

func (L *Line) write() {
    var filepath, str string
    mode := L.getmode()
    day  := L.getday()
    switch mode {
    case "snat":
    {
        filepath = "/var/log/firewall/snat.log." + day
        if L.proto == "PROTO=ICMP" {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.gettype(),L.getcode())
        } else {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.getspt(), L.getdpt())
        }
    }
    case "dnat":
    {
        filepath = "/var/log/firewall/dnat.log." + day
        if L.proto == "PROTO=ICMP" {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.gettype(),L.getcode())
        } else {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.getspt(), L.getdpt())
        }
    }
    case "acl":
    {
        filepath = "/var/log/firewall/acl.log." + day
        if L.proto == "PROTO=ICMP" {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getaction(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.gettype(),L.getcode())
        } else {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getaction(), L.getin(), L.getout(), L.getproto(), L.gettype(),L.getsrc(), L.getdst(), L.getspt(), L.getdpt())
        }
    }
    case "ipv6_snat":
    {
        filepath = "/var/log/firewall/ipv6.snat.log." + day
        if L.proto == "PROTO=ICMP" {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.gettype(),L.getcode())
        } else {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.getspt(), L.getdpt())
        }
    }
    case "ipv6_dnat":
    {
        filepath = "/var/log/firewall/ipv6.dnat.log." + day
        if L.proto == "PROTO=ICMP" {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.gettype(),L.getcode())
        } else {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.getspt(), L.getdpt())
        }
    }
    case "ipv6_acl":
    {
        filepath = "/var/log/firewall/ipv6.acl.log." + day
        if L.proto == "PROTO=ICMP" {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getaction(), L.getin(), L.getout(), L.getsrc(), L.getdst(),L.getproto(), L.gettype(),L.getcode())
        } else {
            str =  fmt.Sprintf("%s_%s %s,%s,%s,%s,%s,%s,%s,%s,%s\n", L.getdate(), L.gettime(), L.getaction(), L.getin(), L.getout(), L.getproto(), L.gettype(),L.getsrc(), L.getdst(), L.getspt(), L.getdpt())
        }
    }
    }
    oF , err := os.OpenFile(filepath, os.O_CREATE|os.O_APPEND|os.O_RDWR, 0644)
    if err != nil {
        fmt.Printf("open log failed: %s!\n", err)
        return
    }

    oF.WriteString(str)
    oF.Close()
}

// set
func (L *Line) setdate(date string) {
    L.date = date
}
func (L *Line) settime(time string) {
    L.time  = time
}
func (L *Line) setmode(mode string) {
    L.mode = mode
}
func (L *Line) setaction(action string) {
    L.action = action
}
func (L *Line) setin(in string) {
    L.in = in
}
func (L *Line) setout(out string) {
    L.out = out
}
func (L *Line) setsrc(src string) {
    L.src = src
}
func (L *Line) setdst(dst string) {
    L.dst = dst
}
func (L *Line) setproto(proto string) {
    L.proto = proto
}
func (L *Line) settype(ltype string) {
    L.ltype = ltype
}
func (L *Line) setcode(code string) {
    L.code = code
}
func (L *Line) setspt(spt string)  {
    L.spt = spt
}
func (L *Line) setdpt(dpt string) {
    L.dpt = dpt
}

// get
func (L *Line) getdate() string {
    return L.date
}
func (L *Line) gettime() string {
    return L.time
}
func (L *Line) getmode() string {
    return L.mode
}
func (L *Line) getaction() string {
    return L.action
}
func (L *Line) getin() string {
    return L.in
}
func (L *Line) getout() string {
    return L.out
}
func (L *Line) getsrc() string {
    return L.src
}
func (L *Line) getdst() string {
    return L.dst
}
func (L *Line) getproto() string {
    return L.proto
}
func (L *Line) gettype() string {
    return L.ltype
}
func (L *Line) getcode() string {
    return L.code
}
func (L *Line) getspt() string {
    return L.spt
}
func (L *Line) getdpt() string {
    return L.dpt
}

func (L *Line) getday() string {
    var day string
    if L.date != "" {
        day = L.date
    } else {
        tm  := time.Now()
        day = tm.Format("2006-01-02")
    }
    return day
}

func delstring(l []string) []string {
    tgt := l[:0]
    for _, s := range l {
        if strings.Contains(s, "["){
           continue
        }
        if strings.Contains(s, "]"){
           continue
        }
        tgt = append(tgt, s)
    }
    return tgt
}

func decode(l []string) *Line {
    var line *Line = new(Line)
    lens := len(l)
    for i := 0; i < lens; i++ {
        if i == 0 {
            line.setdate(l[i])
        } else if i == 1 {
            line.settime(l[i])
        } else if i == 2 {
            line.setmode(l[i])
        } else {
            if strings.HasPrefix(l[i], "ACTION") {
                line.setaction(l[i])
            } else if strings.HasPrefix(l[i], "IN") {
                line.setin(l[i])
            } else if strings.HasPrefix(l[i], "OUT") {
                line.setout(l[i])
            } else if strings.HasPrefix(l[i], "SRC") {
                line.setsrc(l[i])
            } else if strings.HasPrefix(l[i], "DST") {
                line.setdst(l[i])
            } else if strings.HasPrefix(l[i], "PROTO") {
                line.setproto(l[i])
            } else if strings.HasPrefix(l[i], "TYPE") {
                line.settype(l[i])
            } else if strings.HasPrefix(l[i], "CODE") {
                line.setcode(l[i])
            } else if strings.HasPrefix(l[i], "SPT") {
                line.setspt(l[i])
            } else if strings.HasPrefix(l[i], "DPT") {
                line.setdpt(l[i])
            }
        }
    }

    return line
}

func main() {
    args := strings.Split(os.Args[1], " ")
    fmt.Println(args)
    line := delstring(args)
    // fmt.Println(line)
    data := decode(line)
    // 通过接口写入文件
    var log Log =  data
    log.write()
    os.Exit(0)
}
