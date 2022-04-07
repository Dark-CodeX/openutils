pkgname="openutils-sstring"
pkgver="1.6.4"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("MIT")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/prototype_err.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/binary.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/morse_code.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=(
	"bb5410a9a08614d43291bc6fba84a3af02552f7f79b278ec00fcccfaf9975f408520707b56946ffb6e138894907c29eda9547a407fd5060c8c051a2185ebb631"
	"5edc8e4b70c295675c9d48eff4e33c76af506c0d1bcd8b86251d6e9cdacdb83028ce75eebe9440ded79839ba32ee0d5f67a8299c50f1ca5a8ccd5253f8b835fa"
	"1962eea796c94203c88f398f66fefcc9ba29e1626b643e8ab26ca97c6c76dd20828e62f1e899c2c910b2d4d8e5c3e29e810acaa8a108dcc0513331dabfdfa3f5"
	"44f816c35924121c793c33c2e1517a2e48ca1ca1b00d6a627b6ba4e3c18f086794f7d94aa9ef32dca912731e230a3db3a1f54438bd64f14ccc79313b9749c618"
	"4bd742f8cde1ec84f0a8fd95b5be732411545b8c0d066045006aebfdbe375d3e327dba3fe481a958b6b3555a5cf47a3caca28b4c4b1878217b14490d096da7da")

package() {
	echo "Memory Safe String Library in C language."
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/openutils/sstring/sstring.h"
	cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/sstring/prototype_err.h"
	cp "${srcdir}/binary.h" "${pkgdir}/usr/include/openutils/sstring/binary.h"
	cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/openutils/sstring/morse_code.h"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
