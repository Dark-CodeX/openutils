pkgname="openutils-sstring"
pkgver="1.6.7"
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
	"e85c368df1f06d38631eb89efaee08f389483b8e3f163778033fd0a9c99255c565fda142fe4201ddbb1465714c8854e9e2f614a365e9e712b558d5500a381357"
	"03b3a7022677d986388ef42a495a9c8191ba665279b53adf5e118b14fcf98e630054f461e8fd7b992308ba13da931470dd4062eb133e2b50f497471c920db96b"
	"caac2442d8f80d89d1248778ebef6d041fd016fc974e064d50890134f6a68db5c70e903d31275931a40e0c65a2c0d8f2340a834bbe00923a42d83d5fa1f0060d"
	"18d3ec98b71ff20b70163a386f9ff03eea6f9ab7e80f5e2fcc3903899b22bf7fa9071069f5f01b44b30e3bc9da07b0c085c025f7a597a82cddf436f85b64137a"
	"fa1ba89a0e2896f96e47bec3ab8ae4353c850c70d739d65496a2d875b87236766be3ccd06068f349eba4bc270c870ed2299ef1ef79f7745e2a30ce4060065c70")

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
