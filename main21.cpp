#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>

#include <regex>


using namespace std::string_view_literals;

static std::string input[] = {
        "mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
        "trh fvjkl sbzzf mxmxvkd (contains dairy)",
        "sqjhc fvjkl (contains soy)",
        "sqjhc mxmxvkd sbzzf (contains fish)",
};

static std::string input2[]= {
        "jnlgn xqth jtjtrd vhdt rlsr jjhfbn vvrhc hbrplx fntg dtkr fnlqrk vvbqtz prkblp ffj zkkz vmb xlvrggj qjg sfghbs srjv vphhllt fvjkp qszsz zhszc rzbncvnc mfbfsz xdjk plxs xgc gfzmpxq rmpfkv tglj rsmstv lfckh rkllz qczmsk xpbxbv zdpxfl zfsbvl mmdcl nzqx gzsdm mqv cmffmd gjlql htmb fqrm prtvmb smbdlcg zgzt zcvs qcksk trpbj jbslsbv lhtpf jgjrj tqlbk (contains shellfish)",
        "zhszc mgrr zgdt txldvd tvz xlvrggj zvrm brvz rzbncvnc kzklp zcxq krpcn rxv xqth ztpmz trpbj hnngrhk dqspdq qmqbz qpndpm dfsnq sfghbs jgjrj gjlql dktlp prtvmb zxnjkf fvjkp prkblp jjhfbn crjpt rsmstv qthxnb tcflf lfckh fsmqv rnjlpq vvnmqt scnc mqv khmzbj xkmz hbrplx lxpqkn gzsdm nxvzp fktgv rkkgm hlhc xpbxbv kzrk pffccf ndkmq bxc vmb czzx vdjtl rkkpgs zgzt mmdcl sdggf jszqhpf jtjtrd zhbtz fntg pdst qltvp rbjdgh zdpxfl nnrctqh hprqd tcfgv vphhllt jrpm mnn tglj vvrhc mqscmlf qnc gtqfrp dtkr srjv vhr htmb ffj xrvgdh qszsz cqkprv trjqbr cqs (contains soy, wheat, fish)",
        "xbzns trjqbr prkblp mbdbf gfzmpxq gtqfrp fntg frnmdqx rlsr zgzt qvjk cmffmd srfm qltvp brkds lkzfc qthxnb plxs tsjtr dkshp qrbbf rmpfkv sxpbg qczmsk xlvrggj nzqx rnjlpq zkkz mvmhqbpz tcflf vvrhc tvdntm qplx btttz gjlql zsd vvz sgn rkkgm vmb zhszc pdst qcksk tkv tcfgv rkkpgs vhdt smbdlcg lxpqkn pffccf krnfm lfckh khmzbj htmb tvz crbd fqrm fnpkmh fsmqv txldvd qktcqv hbrplx hzxx xqth xpbxbv jtjtrd fvt (contains peanuts, sesame, eggs)",
        "nchjqv frnmdqx nxvzp tdszhqn jnlgn nzqx fnpkmh jszqhpf dlzb qltvp dtkr mbdbf jmvv zhbtz vhdt ltbqt ftrnplt rtjbpd vvbqtz fsmqv vmq brkds xpbxbv nltv cghkbp vrgdk fvjkp qrbbf krnfm xgc hbjmtc tcflf tftpnc zvrm flxplq qpndpm tbnlrpb qpkbc fntg zhszc vphhllt qmcdlz lnvrg srjv jtjtrd crjpt rnjlpq zbnv fnlqrk zljsv zsd xqth prpbcv vvz pffccf rkkgm gjlql khmzbj lhtpf mgrr mfbfsz kzklp zxnjkf btttz gtqfrp hxcc rlsr mbx nhldb rzbrrr vhmpqd zcxq zkkz lkzfc tkv tfn qvks zkxxnhn mvmhqbpz lzxpn dqspdq nnrctqh lxpqkn htmb crbd tvz jrpm srfm txldvd qczmsk (contains eggs, sesame)",
        "krnfm jrpm xbzns lnvrg rzbncvnc vhr mqscmlf xqth ffj zgzt xkmz nchjqv vmq jtjtrd xzd qmcdlz mqv smbdlcg qvjk khmzbj xgc dkshp prpbcv zptr vhdt nnrctqh tqlbk zcxq mnn vhmpqd qplx crjpt zhszc jjhfbn ltbqt dktlp tftpnc hxq vphhllt gtqfrp rlsr zdpxfl flxplq plxs sgmsn cqs fqrm mmdcl qlrxfv jmvv nltv frnmdqx cghkbp jszqhpf sxpbg vdjtl tkrflnf qjg fvjkp jnlgn kzklp lfckh mgrr fntg xpbxbv hlhc tvz tdszhqn tfn srfm ztpmz sfghbs zgdt rxv trpbj qczmsk (contains shellfish)",
        "htmb srfm qcksk ftssfh czzx fntg rbbnskn rnjlpq rxv rsmstv vrgdk gtqfrp rd flxplq hbrplx vmq xdjk vvrhc nhldb ztpmz jmvv tftpnc mfbfsz szsrnsc hprqd zptr mvmhqbpz mnn qjg srjv jtjtrd tqlbk vdjtl nltv mqscmlf rkkpgs prtvmb fvjkp hnngrhk ftrnplt lxpqkn tvdntm ffj xlvrggj bmpnrhb jrlzcv zhszc xgc vpvm zhbtz vvz mbdbf lzxpn zdpxfl qktcqv qvjk rlsr khmzbj (contains soy, fish)",
        "rmzbr jtjtrd fvghn jjhfbn tsjtr mfbfsz tglj qthxnb cqkprv trjqbr zqnn tkrflnf lnvrg kssgts vvbqtz rzbrrr ndkmq zfsbvl qrbbf vvz dfsnq gpvcz dqspdq vhdt gzsdm phkxp rlsr prtvmb jnlgn rkllz ltbqt zljsv nchjqv fvt znhjn fsmqv cghkbp sgn nzqx fvjkp tbnlrpb fntg pffccf bxc zhszc gtqfrp cqs nxvzp mqv xpbxbv jgjrj zgdt srjv tftpnc lsnnzp lxpqkn xzd tkv qmcdlz (contains soy)",
        "nhldb tlbtr fvghn lfckh tftpnc rlsr hxq zptr htmb lzxpn smbdlcg qplx zdpxfl hnngrhk dkshp qszsz qlrxfv plxs nxvzp xqth rd qmqbz tzc sxpbg mmdcl jnlgn nzqx rbjdgh vmb vvrhc scnc rzbncvnc prpbcv jrpm zxnjkf vhr nltv fktgv xzd fntg crbd vhmpqd pdst nnrctqh zhszc rnjlpq tsjtr krpcn rzbrrr zgzt xpbxbv jtjtrd gjlql fnpkmh cghkbp cmffmd trjqbr mqscmlf gtqfrp khmzbj dfsnq hzxx rbbnskn srjv xrvgdh fvjkp qmcdlz hbrplx xgc cqs mvmhqbpz szsrnsc hprqd qktcqv znhjn mfbfsz (contains sesame, eggs)",
        "nzqx fktgv vmb jszqhpf ffj fvjkp qcksk xqszlhq qvks zcvs pdst rmpfkv nchjqv dtkr qplx tfn crbd zdpxfl sxpbg xpbxbv bmpnrhb zgdt zkkz rtjbpd qrbbf tvdntm xkmz zbnv sfghbs vphhllt dktlp nnrctqh pffccf xrvgdh qszsz qmcdlz gjmbv vhr qvjk rkllz rlsr xzd tzc rkkgm txldvd cqs fntg xdjk hbrplx jnlgn hxcc mgrr lfckh qnc ftrnplt vvrhc frnmdqx xgc jbslsbv gfzmpxq rzbrrr gtqfrp rbjdgh jtjtrd tdszhqn rd lzxpn srjv rsmstv ndkmq rbbnskn tsjtr fnlqrk srfm fvt vvnmqt cvnmx scnc lxpqkn tcfgv zptr zhszc vvbqtz mmdcl hnngrhk mqv prkblp brkds sgn (contains wheat, soy, peanuts)",
        "qltvp mfbfsz rtjbpd fntg jtjtrd fvt rmzbr rzbrrr rd xqszlhq xrvgdh fvghn frnmdqx zdpxfl mbdbf rnjlpq mnn jgjrj rkllz rlsr cvnmx gzsdm lkzfc mqv nxvzp rmpfkv pffccf gpvcz zptr zkxxnhn qnc sgmsn qvjk dlzb fnpkmh txldvd trjqbr qlrxfv vhdt lfckh mvmhqbpz ftssfh krnfm hxq mbx jjhfbn fvjkp hbrplx bxc khmzbj lzxpn tqlbk lxpqkn vrgdk cqkprv zhszc jrpm trpbj hxcc prkblp mqscmlf xqth tcflf brkds tvdntm fnlqrk vvrhc vvnmqt xlvrggj qpndpm kssgts dfsnq zqnn pdst tbnlrpb qplx zhbtz mmdcl xpbxbv qpkbc (contains soy, sesame)",
        "lnvrg ftssfh tbnlrpb zhszc xbzns hxq cmffmd cghkbp jmvv zgdt ftrnplt nxvzp xlvrggj vphhllt tglj vhr trjqbr flxplq kstd tlbtr qrbbf gtqfrp rbjdgh xpbxbv jbslsbv lxpqkn zsd fktgv vvrhc mnn brkds vrgdk nchjqv xqszlhq ndkmq hprqd czzx hlhc xgc dkshp jgjrj xqth cvnmx hbjmtc zgzt rtjbpd nhldb ltbqt zcvs qpkbc fntg xzd gzsdm fvjkp zfsbvl lzxpn fqrm plxs bmpnrhb zljsv tvz vpvm pffccf jtjtrd qlrxfv (contains sesame, fish, shellfish)",
        "zcvs qnc zfsbvl xkmz bvdqd tzc fvjkp zxnjkf phkxp rnjlpq znhjn jgjrj vhr krnfm qcksk szsrnsc zhszc tvdntm gzsdm fntg jtjtrd vrgdk vvnmqt jrpm fnpkmh xbzns kzklp rlsr tdszhqn kssgts hbjmtc rmpfkv rkllz xdjk kzrk qczmsk nnrctqh ftrnplt tcfgv qltvp trjqbr rkkgm tcflf gjlql hbrplx srfm sgmsn qrbbf tlbtr tftpnc fvghn hprqd tqlbk gtqfrp hnngrhk fktgv ndkmq prkblp lnvrg mbx xgc gjmbv flxplq cghkbp rmzbr ftssfh nchjqv nxvzp xqth qktcqv jszqhpf jbslsbv dtkr qpndpm bmpnrhb tglj xpbxbv plxs (contains wheat, sesame)",
        "fvghn mvmhqbpz jjhfbn zgzt krnfm xqszlhq qvks fntg kssgts jmvv dtkr xdjk nchjqv vvrhc bmpnrhb qczmsk zcxq lhtpf prkblp tbnlrpb rlsr xlvrggj xpbxbv htmb qmqbz fvjkp phkxp prpbcv mmdcl kstd zgdt hbrplx krpcn ltbqt jtjtrd jbslsbv rxjsq lxpqkn sfghbs mfbfsz xkmz tcfgv hbjmtc mbx vvz nnrctqh tkrflnf dlzb vhdt rsmstv rmpfkv brvz vmq zptr gtqfrp rnjlpq zqnn prtvmb rbbnskn qpndpm qvjk ftssfh zhbtz rbjdgh kzklp ztpmz nxvzp hzxx (contains peanuts, eggs, dairy)",
        "xlvrggj nhldb rxjsq ltbqt fntg xgc zqnn vmb zvrm mqv jtjtrd vvz qjg mbx rkllz hxcc ftrnplt zsd jjhfbn jmvv scnc crjpt zcvs zhszc vphhllt tfn htmb mqscmlf rlsr qcksk lhtpf dtkr zkxxnhn zgdt qrbbf sgmsn srfm rd lxpqkn xqszlhq vhr gtqfrp brvz tcflf fvjkp bmpnrhb tqlbk gzsdm tcfgv qczmsk mgrr qktcqv fvghn hxq qvjk (contains fish, eggs, peanuts)",
        "tftpnc qktcqv dlzb vhmpqd qpndpm xlvrggj bmpnrhb vrgdk hbrplx kssgts kzklp zgzt mvmhqbpz krpcn vvnmqt gjlql gfzmpxq jtjtrd zhszc xpbxbv xbzns mbx vmq crbd vpvm krnfm qmqbz txldvd bxc qrbbf kstd fvt tqlbk tdszhqn rzbrrr sgn zqnn prpbcv fvjkp rkkpgs qjg kzrk qczmsk jgjrj rd rlsr fntg lhtpf tsjtr qnc qmcdlz ftrnplt szsrnsc xgc sfghbs xkmz fnpkmh zcvs rnjlpq prtvmb xqszlhq dtkr rkkgm srjv rtjbpd mqv qplx jszqhpf tzc zxnjkf gpvcz brvz ztpmz ltbqt cvnmx tbnlrpb (contains fish)",
        "plxs fvjkp hzxx rmzbr xbzns xlvrggj flxplq hbjmtc xpbxbv qnc sgn hxcc zhszc trjqbr qczmsk znhjn prtvmb zljsv qplx vphhllt vvnmqt zxnjkf cqs brkds gjlql rkllz zdpxfl lzxpn phkxp zsd frnmdqx hxq lsnnzp gtqfrp qltvp rsmstv hprqd fntg gfzmpxq vvbqtz mgrr tkrflnf jszqhpf vvz fvt jrlzcv prkblp kssgts nnrctqh ndkmq nltv tqlbk rnjlpq pffccf jtjtrd lkzfc rbbnskn dfsnq qvjk rtjbpd rmpfkv zbnv qcksk lnvrg qmqbz xqszlhq tvdntm zptr sgmsn txldvd (contains eggs, shellfish, fish)",
        "xkmz qktcqv frnmdqx qpndpm tfn ftrnplt xpbxbv rsmstv gfzmpxq zhszc gpvcz jszqhpf ltbqt fvghn kssgts khmzbj krnfm ndkmq rbbnskn scnc fqrm qmcdlz zqnn qmqbz xlvrggj rlsr ftdbz jgjrj gtqfrp jrlzcv zljsv xqth mnn tlbtr vvz dktlp rkllz gzsdm fntg cqs tftpnc fnlqrk tdszhqn hzxx fvjkp qltvp fnpkmh nltv qvjk tsjtr tcfgv (contains sesame)",
        "hbrplx xpbxbv mnn rmpfkv xdjk ftdbz fvt htmb vphhllt rtjbpd ndkmq xlvrggj xqszlhq xbzns rlsr qpkbc gzsdm krnfm srfm prtvmb fvjkp zqnn nzqx rzbncvnc tglj mqv qmqbz qmcdlz nhldb ffj nxvzp szsrnsc hnngrhk jrpm dqspdq plxs lzxpn xqth lhtpf zdpxfl sfghbs jrlzcv tcflf qltvp jjhfbn mqscmlf tkv hbjmtc tcfgv flxplq dfsnq crjpt trjqbr jnlgn ltbqt jszqhpf zgzt qszsz dktlp jmvv brkds rbbnskn lnvrg tfn prkblp tvz rkllz zcxq jtjtrd prpbcv gtqfrp vrgdk krpcn rkkgm cqs qjg zhszc zvrm rd rbjdgh tvdntm xkmz (contains fish, sesame)",
        "vmq cqkprv rkllz mqscmlf dqspdq rxjsq nxvzp fvjkp jtjtrd xpbxbv lzxpn tcflf qthxnb kzrk gtqfrp tqlbk tcfgv vhdt fsmqv rd cvnmx vvrhc hxcc zgzt qszsz ftdbz qltvp czzx qcksk lfckh gzsdm bvdqd qczmsk rlsr brvz tdszhqn kzklp lkzfc zhszc crjpt vmb rbjdgh rtjbpd tkrflnf hzxx xrvgdh xbzns fntg vpvm mfbfsz jnlgn qjg nzqx zxnjkf tvz zptr sgn fnlqrk zqnn vrgdk rbbnskn pdst (contains wheat, dairy)",
        "lfckh jgjrj xpbxbv lkzfc fntg mfbfsz vmq vrgdk rnjlpq tqlbk szsrnsc rkkpgs rbjdgh jrpm plxs zgdt qthxnb jtjtrd zkxxnhn bmpnrhb lzxpn mbx hbjmtc vhr lnvrg gjlql zqnn gtqfrp vvnmqt qnc qpndpm xkmz fvghn mbdbf zbnv rzbrrr qlrxfv vpvm znhjn qktcqv tsjtr qltvp rd pdst fvjkp xlvrggj rzbncvnc qvjk sxpbg czzx rlsr qczmsk (contains shellfish, soy)",
        "zqnn fvjkp qmqbz hnngrhk vdjtl xpbxbv srfm zhszc fktgv sxpbg vvz btttz lxpqkn hzxx lnvrg vhdt lfckh vphhllt rnjlpq gtqfrp tzc qktcqv plxs zsd xlvrggj qszsz rzbncvnc rkkgm dkshp jgjrj qlrxfv ztpmz mgrr fntg jrpm trpbj jtjtrd txldvd smbdlcg pdst vrgdk rkllz bxc rmpfkv kssgts zljsv (contains soy)",
        "cvnmx sdggf hnngrhk ltbqt srfm flxplq qthxnb prpbcv zkkz tcflf gpvcz dlzb bvdqd zvrm plxs znhjn fktgv xgc rzbrrr hzxx jgjrj rzbncvnc dkshp fsmqv fvt fvghn trpbj jnlgn qmcdlz nnrctqh brvz qpndpm kzrk xpbxbv xlvrggj nltv kzklp krnfm crbd ffj dqspdq kstd qczmsk dtkr vhdt qjg sgmsn frnmdqx rmzbr jtjtrd qlrxfv xbzns rlsr fvjkp qrbbf fntg trjqbr ftdbz sgn txldvd zptr vmq prkblp lxpqkn lkzfc rkkpgs tvdntm tkv rbjdgh krpcn mgrr srjv mbx vvrhc mbdbf qnc phkxp gtqfrp hbjmtc zsd (contains fish, sesame)",
        "zgdt czzx rxv cghkbp tglj rkkpgs vdjtl ftdbz vhr tdszhqn tsjtr qmcdlz hprqd plxs xlvrggj mmdcl znhjn qczmsk frnmdqx jbslsbv vvbqtz tlbtr gtqfrp zkxxnhn fsmqv qmqbz zbnv smbdlcg brkds qpkbc qjg hbjmtc dqspdq zcxq rlsr nchjqv ltbqt sdggf qrbbf kzrk lkzfc ftrnplt zqnn tvz zsd fntg sfghbs srfm dtkr crjpt htmb hnngrhk nnrctqh rbbnskn rsmstv mfbfsz fvt zkkz jtjtrd zhszc pdst jjhfbn xpbxbv tkv nxvzp qcksk vvrhc fktgv dfsnq prkblp ftssfh vvz (contains shellfish, eggs, peanuts)",
        "trjqbr ndkmq fntg trpbj vhmpqd btttz prkblp brkds tfn qthxnb lnvrg xlvrggj xpbxbv xrvgdh hxq qmcdlz hbjmtc ftrnplt tkrflnf rbbnskn phkxp dfsnq sxpbg fvjkp gfzmpxq pffccf qpndpm sdggf zhbtz ztpmz zsd sgn zhszc ftssfh rd zvrm rlsr rkllz prtvmb rmpfkv bxc cqkprv qjg zkkz fvt mqv jtjtrd qczmsk ffj dktlp nnrctqh tcfgv mbx hbrplx lsnnzp (contains peanuts, soy, sesame)",
        "hzxx vpvm vphhllt xzd gpvcz btttz jtjtrd dqspdq sgmsn tvz xlvrggj ftdbz fnlqrk tglj zljsv rzbncvnc fsmqv xpbxbv rmpfkv qmqbz fntg pffccf zdpxfl cmffmd vvrhc rd zhszc qpndpm qszsz ztpmz lfckh fktgv zkkz xdjk nxvzp hxcc vrgdk qvks xrvgdh rxv rbbnskn qvjk nzqx vvz ndkmq zsd tkrflnf nltv mnn fnpkmh frnmdqx cqkprv vhmpqd kssgts mvmhqbpz dkshp qlrxfv tcfgv rkkgm tkv tsjtr zgzt dtkr cqs jszqhpf lkzfc hxq smbdlcg hprqd fvghn qnc prtvmb tlbtr rlsr lnvrg gzsdm tvdntm gtqfrp rzbrrr qthxnb (contains sesame, wheat, fish)",
        "nhldb vrgdk txldvd zhszc sgmsn czzx kssgts tcflf jgjrj mqscmlf rxv jszqhpf scnc lsnnzp xdjk qvks prtvmb cvnmx jrpm hzxx jtjtrd sgn rtjbpd dktlp jbslsbv fvt zvrm lhtpf trjqbr gtqfrp rlsr tkv sxpbg prpbcv fvghn hbrplx kzklp nnrctqh gzsdm zbnv lxpqkn ftdbz srjv tzc pffccf mmdcl szsrnsc tqlbk ltbqt fvjkp tdszhqn btttz mgrr sdggf dqspdq rbjdgh xqth gfzmpxq nltv rbbnskn flxplq rnjlpq jrlzcv qnc tbnlrpb qltvp smbdlcg qpndpm xpbxbv zgdt vdjtl dtkr tlbtr xlvrggj pdst zgzt vhmpqd rzbncvnc (contains shellfish, soy)",
        "mvmhqbpz ffj xlvrggj crbd jtjtrd dtkr hbjmtc zgdt gtqfrp szsrnsc lnvrg kzklp tftpnc khmzbj scnc lfckh rxv nzqx jrlzcv gzsdm mmdcl zcvs hzxx ndkmq sgmsn xzd txldvd mnn fnlqrk rlsr rtjbpd plxs dkshp sgn srfm nchjqv fqrm tkrflnf hxcc bxc xpbxbv tlbtr nhldb qktcqv rbbnskn ztpmz zhszc nxvzp nltv fvghn zhbtz kssgts rsmstv qvks qplx vpvm lsnnzp cqkprv qrbbf hbrplx tfn rmpfkv crjpt brvz xkmz sdggf vvz vphhllt rxjsq fntg tzc prpbcv rkkgm fktgv zcxq (contains sesame, fish)",
        "scnc cqkprv kssgts szsrnsc cqs tkrflnf zcvs crjpt dktlp trjqbr qjg vhr lzxpn sdggf xkmz khmzbj ftrnplt rd qvjk fntg qthxnb xqth mnn jtjtrd ftdbz brkds pffccf cghkbp jgjrj dkshp vvrhc qktcqv zptr sxpbg vvbqtz sfghbs rzbrrr lfckh ffj rmpfkv lxpqkn mgrr lnvrg vmq czzx nltv qczmsk phkxp jszqhpf txldvd vvz tzc tdszhqn zgdt tvz zhszc rlsr vrgdk prpbcv znhjn fvjkp prkblp fnpkmh nhldb zxnjkf xlvrggj zvrm qpndpm ltbqt jrpm ftssfh tvdntm hxcc nnrctqh xbzns xpbxbv (contains soy)",
        "zhszc nxvzp hbjmtc xgc gzsdm kzrk vvnmqt mqscmlf hzxx rlsr rzbrrr tcflf rmpfkv jtjtrd szsrnsc vmb zdpxfl frnmdqx gfzmpxq sgn vhdt qplx jbslsbv lsnnzp xpbxbv vmq gtqfrp crbd zvrm xdjk lkzfc zqnn bxc fvjkp tbnlrpb qczmsk zkxxnhn nzqx rxv xlvrggj tcfgv lzxpn vvrhc gjlql lhtpf fvghn tftpnc gpvcz txldvd (contains peanuts)",
        "xlvrggj rlsr gjlql trpbj kzklp rzbncvnc nhldb xkmz hlhc fqrm rzbrrr dfsnq mvmhqbpz zkxxnhn vdjtl dlzb bmpnrhb kzrk rtjbpd xpbxbv flxplq tftpnc qmqbz krnfm fntg jszqhpf qltvp sgmsn trjqbr tsjtr dqspdq tvdntm qplx fsmqv vvnmqt qszsz cqs fvjkp nnrctqh tcfgv rnjlpq xbzns jtjtrd tzc gtqfrp xqszlhq mmdcl tbnlrpb rxjsq kstd fvt sgn zbnv fnpkmh (contains dairy, sesame)",
        "fntg jszqhpf xrvgdh ztpmz xpbxbv qszsz hbjmtc plxs cghkbp tkv zhszc cmffmd lnvrg qjg tvz vvz qnc flxplq qpkbc rmpfkv tbnlrpb dlzb bmpnrhb hlhc rmzbr hxcc zhbtz gzsdm gtqfrp mqscmlf qvjk fvghn hbrplx bxc qltvp jrlzcv vhr tzc lhtpf zbnv sfghbs kssgts vhmpqd hnngrhk qthxnb tftpnc krpcn zgzt fvjkp rsmstv vdjtl jtjtrd mnn jbslsbv rlsr ltbqt tglj (contains wheat, dairy, sesame)",
        "crbd krnfm jtjtrd dlzb tcfgv dfsnq ltbqt rkkpgs ffj zgzt dkshp ztpmz vdjtl crjpt smbdlcg phkxp tkrflnf kzrk tftpnc bvdqd vhr frnmdqx scnc rzbrrr sfghbs xpbxbv xzd gpvcz qpkbc pdst cqkprv rzbncvnc xlvrggj srjv ftdbz rsmstv qrbbf sxpbg prkblp hxq hlhc zgdt rlsr vvrhc pffccf vphhllt vmb hnngrhk bxc fvghn czzx nxvzp vhmpqd gtqfrp lkzfc lsnnzp prpbcv lnvrg xkmz xqth fvjkp tcflf rkkgm fnpkmh zkxxnhn jszqhpf qmqbz rbbnskn qvks tkv nltv tdszhqn kstd qplx fntg (contains sesame, eggs, peanuts)",
        "zqnn jtjtrd rzbncvnc fqrm fvjkp zsd vhr dkshp btttz fvt fntg lnvrg rlsr xgc sgn rkllz dlzb vmb qktcqv phkxp szsrnsc txldvd rmpfkv mbx gzsdm xlvrggj tkrflnf mfbfsz xrvgdh hxcc qmcdlz tftpnc tkv rsmstv xdjk zljsv krpcn zgdt smbdlcg prpbcv gtqfrp qjg qvks vphhllt tdszhqn prtvmb zhszc cghkbp qczmsk vrgdk gfzmpxq (contains fish)",
        "vhmpqd jjhfbn xpbxbv brvz qthxnb lkzfc xrvgdh fvt xqth tdszhqn gtqfrp tkrflnf kzrk zgdt dkshp kssgts mbx gjlql jtjtrd cvnmx gjmbv tvz zptr kstd rxv fntg prpbcv qplx zbnv jbslsbv trjqbr mfbfsz fvjkp ftdbz phkxp mgrr tvdntm dlzb crjpt vvz tsjtr xlvrggj nhldb zhszc fvghn qczmsk tftpnc htmb ndkmq rbjdgh vvrhc (contains wheat, soy)",
        "xlvrggj tglj rzbrrr dtkr trjqbr prtvmb zvrm jnlgn xqszlhq cqkprv vphhllt fqrm qczmsk cmffmd khmzbj rbbnskn zkxxnhn xpbxbv jbslsbv fvjkp xbzns mmdcl brvz rkkpgs fnpkmh scnc gtqfrp nltv zhszc fvt rmpfkv qjg mgrr qpndpm zsd vvbqtz tftpnc ltbqt jtjtrd prpbcv dqspdq rlsr ztpmz (contains eggs)",
        "fnpkmh hprqd kssgts czzx mnn tlbtr ltbqt bvdqd vrgdk tftpnc ftssfh hxcc tfn vhdt fntg szsrnsc bmpnrhb zljsv hbrplx lzxpn ztpmz kzrk kstd xqszlhq rtjbpd mqv qpkbc tzc zbnv qvjk rlsr sfghbs phkxp qszsz qnc txldvd nxvzp rbjdgh lkzfc xrvgdh gtqfrp gpvcz qczmsk nnrctqh tdszhqn dktlp hbjmtc rzbncvnc qrbbf zfsbvl vphhllt xlvrggj dlzb xdjk zhszc jtjtrd zkxxnhn dtkr rkllz jrlzcv vdjtl lfckh tkrflnf btttz zqnn rbbnskn fvjkp ftdbz krnfm hnngrhk rmzbr pffccf flxplq zgzt ndkmq zptr (contains wheat, eggs)",
        "szsrnsc nnrctqh rxv prpbcv dfsnq ndkmq rxjsq qlrxfv jgjrj dkshp rkllz zdpxfl scnc rlsr qnc crjpt lsnnzp nhldb zcxq xdjk gzsdm hxq fvjkp mbdbf xpbxbv tvz tqlbk ftdbz crbd bxc zkxxnhn fntg pdst lnvrg krpcn vrgdk tsjtr fnpkmh zhszc tzc qmcdlz qpkbc kssgts gtqfrp gfzmpxq qszsz trpbj phkxp hlhc xzd xlvrggj zljsv (contains wheat)",
        "nchjqv mgrr tvz prpbcv rlsr sgn jjhfbn gjlql zgzt nhldb vmq gtqfrp xrvgdh cghkbp nzqx vvbqtz bmpnrhb mvmhqbpz fnlqrk brkds hzxx vvz fvghn krnfm tbnlrpb zcxq gzsdm kssgts rkllz fntg tlbtr zljsv rzbncvnc kzrk rbbnskn sdggf ftdbz lnvrg zbnv lxpqkn vhr szsrnsc rxv fktgv zcvs zptr jgjrj mfbfsz cqkprv jbslsbv dqspdq xpbxbv lzxpn jtjtrd rbjdgh fvjkp rtjbpd cqs htmb gpvcz lkzfc tdszhqn hprqd zhszc sxpbg qjg fqrm qvjk tkrflnf xdjk vvrhc cvnmx zsd jszqhpf qpndpm rkkgm krpcn rxjsq vpvm mbdbf qltvp rsmstv (contains eggs)"
};

static std::string input3[] = {

};

static std::vector<std::string> split(std::string s, std::string delimiter) {
    auto scopy = s;
    std::vector<std::string> result;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    result.push_back(s);
    return result;
}

static std::map<std::string, std::string> known_ing;
static std::set<std::string> all_allergs;
static std::map<std::string, int> all_ings;

void add_ing(const std::string& ing) {
    if (all_ings.find(ing) == all_ings.end()) {
        all_ings[ing] = 1;
    } else {
        auto nr = all_ings[ing];
        nr++;
        all_ings[ing] = nr;
    }
}

struct Food {
    std::set<std::string> ings;
    std::set<std::string> allergs;
    void print() {
        std::copy(ings.begin(), ings.end(),
                  std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << "(";
        std::copy(allergs.begin(), allergs.end(),
                  std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << ")" << std::endl;
    }

    bool operator<(const Food& other) {
        std::set<std::string> a = ings;
        a.insert(allergs.begin(), allergs.end());
        std::set<std::string> b = other.ings;
        a.insert(other.allergs.begin(), other.allergs.end());
        return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }
};

std::vector<Food> foods;

bool remove_known() {
    bool result = false;
    for (const auto&[known_ing, known_allerg] : known_ing) {
        for (auto& food: foods) {
            result |= (food.ings.erase(known_ing) != 0);
            result |= (food.allergs.erase(known_allerg) != 0);
        }
    }
    return result;
}

bool remove_obvious() {
    bool result = false;
    for (auto& food: foods) {

        if (food.ings.size() == 1 ) {
            if (food.allergs.size() == 1) {
                known_ing[*food.ings.begin()] = *food.allergs.begin();
            } else {
                assert(false);
            }
            food = {};
            result = true;
        }
    }
    return result;
}


bool remove_empty() {
    bool result = false;
    for (auto it = foods.begin(); it != foods.end(); ) {
        if (it->ings.empty()) {
//            assert(it->allergs.empty());
            it = foods.erase(it);
            result = true;
        } else {
            ++it;
        }
    }
    return result;
}

bool build_2_clusters(){
    std::vector<Food> distilled_foods;
    bool result = false;
    for (int i = 0; i < foods.size(); i++) {
        for (int j = i; j < foods.size(); j++) {
            if (i == j) continue;

            std::set<std::string> ings_intersect;
            set_intersection(foods[i].ings.begin(),foods[i].ings.end(),foods[j].ings.begin(),foods[j].ings.end(),
                             std::inserter(ings_intersect,ings_intersect.begin()));

            std::set<std::string> allergs_intersect;
            set_intersection(foods[i].allergs.begin(),foods[i].allergs.end(),foods[j].allergs.begin(),foods[j].allergs.end(),
                             std::inserter(allergs_intersect,allergs_intersect.begin()));


            if (ings_intersect.empty() || allergs_intersect.empty()) {
                continue;
            }

//            std::cout << "intersection " << std::endl;
//                std::copy(ings_intersect.begin(), ings_intersect.end(),
//                          std::ostream_iterator<std::string>(std::cout, " "));
//            std::cout << "\n vs  " << std::endl;
//                std::copy(allergs_intersect.begin(), allergs_intersect.end(),
//                          std::ostream_iterator<std::string>(std::cout, " "));
//                std::cout << std::endl<< std::endl<< std::endl;

            // mark common parts (??)
            if (ings_intersect.size() == allergs_intersect.size() && ings_intersect.size() == 1) {
                result = true;
                known_ing[*ings_intersect.begin()] = *allergs_intersect.begin();
            } else {
                Food food;
                food.ings = {ings_intersect.begin(), ings_intersect.end()};
                food.allergs = {allergs_intersect.begin(), allergs_intersect.end()};
                distilled_foods.emplace_back(std::move(food));
            }
        }
    }

    std::cout << "Process  " << distilled_foods.size() << " distilled foods " << std::endl;
    for (auto&& distilled: distilled_foods) {
        if (auto it = std::find_if(foods.begin(), foods.end(), [&distilled](const Food& existing){
            return existing.allergs == distilled.allergs && existing.ings == distilled.ings;
        }); it == foods.end()) {
            result = true;
//            std::cout << "New " << std::endl;
//            distilled.print();
            foods.emplace_back(std::move(distilled));
        }
    }

    return result;
}

int _21() {
    for ( auto line : input2) {
        auto ing_allergs = split(line, " (contains ");
        assert(ing_allergs.size() == 2);
        auto ings = split(ing_allergs.at(0), " ");
        auto allergs = split(ing_allergs.at(1).substr(0, ing_allergs.at(1).size()-1), ", ");

        Food food;
        food.ings = {ings.begin(), ings.end()};
        food.allergs = {allergs.begin(), allergs.end()};
        food.print();
        foods.emplace_back(std::move(food));

        for (auto& ing : ings) {
            add_ing(ing);
        }
        all_allergs.insert(allergs.begin(), allergs.end());
    }

    std::cout << "before" << std::endl;
    std::cout << "- foods " << foods.size() << std::endl;
    std::cout << "- known_ing " << known_ing.size() << std::endl;

    bool something_changed = false;
    size_t it_nr = 0;
    do {
        something_changed = false;
        something_changed |= remove_obvious();
        something_changed |= remove_known();
        something_changed |= remove_empty();
        something_changed |= build_2_clusters();
        ++it_nr;

    std::cout << "after" << std::endl;
    std::cout << "- foods " << foods.size() << std::endl;
    std::cout << "- known_ing " << known_ing.size() << "/" << all_allergs.size() << std::endl;
    std::cout << "it_nr " << it_nr << std::endl;

    } while(something_changed);

    size_t sum = 0;
    for (const auto&[known_ing, known_allerg] : known_ing) {
        std::cout << known_ing << ": " << known_allerg << std::endl;
    }

    for (const auto& [ing, ing_appears]: all_ings) {
        if (!known_ing.contains(ing)) {
            sum += ing_appears;
        }
    }
    std::cout << sum << std::endl;

    return 0;
}

