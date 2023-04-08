pkgname="openutils-sstring"
pkgver="2.0.0"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/prototype_err.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/binary.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/morse_code.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=(
	"c4de375cd644813e1b280ae46e928c477f2887ff8ef6e4086ea15115551381eb95fea1adf2451688e18c0feeb7f1b6a159fbfa59a20a655d06d60ff64c5e3098"
	"0679eac5e59090d7d473e1e4e964178a23632e50e3b71320f0edb0ae5f95def027ffdab34ffbeb6a35c10f4ef6b7de687db45199af72196f15944a1873b21071"
	"9f5f693e2d418fd2bd5c0492b34ea8f722b50ed11b43259ef6768ab5eca8f12936e15106a76fa37408cbc33384a939612bdf8f2f3b231e3de8a49061050a6dfc"
	"ef4041b712014d35edcbd489cbad6de8446c0720b4434d9212d43a8a8e5ba66e64fd77abc0603997007060ba9174b4a2187a9dad23821ca5ff716513e38df835"
	"5e3552cf720f09b57bc0b865f4e90d25fd08c4659edcb7bc3158fa13da5deb9ed97043555f8d58ecc10cf08198205147258584f02aadfea6bf71b07a2d8fce91")

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
