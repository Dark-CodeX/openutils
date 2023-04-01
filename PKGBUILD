pkgname="openutils-sstring"
pkgver="1.7.4"
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
	"9647efbf011abafb9d0610370c39ce4cbcc6c4e53a3c579e3ee6c493841b7add1c4cf246707bdcaf5ec10db2ef0ce23448be157cc2c4e8a7ed8db4f5308b3318"
	"254522d371731e423a171ce9cf1b096df5a3b29bfb03188316cbdb2e9eb3094b47a40f3b8149442590212c0303985e3668266b829cff66e281d694f7a5dbb3d8"
	"43213cbb31d74cd440b6df9b604a325f508a9104273c853b98f2ad78f62434ccf2665ddacdbb56a649cd8a898d5db6d9ff04f98dfd8f17efd5de8fdd69da283a"
	"0fe1267cbc6d996a1df0bba7e24cf89fe5e04e169a4579d5bb21186a75b3d44b11aa9d05b6c54174a05a12c0214bf4414f7b0f846ac27cd2850a06fb215f382f"
	"e7c56fd09e9dc760b5d732a9c58db7174bcf41592950a8da2ed3934c8ce69f5ef5e1d572c88ca503f3f615151f3b458c1f23b1ca99200bfc61b761c07f19969f")

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
