pkgname="openutils-date_time"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="Date and time classes for C++."
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("MIT")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"b5e6bdf54aa6e008de409dea62ef7f703739c41db99c5d871faa27ffe87c5b624184a2bdd10d757cbce5aa17f4cd8965981f7f79d34a6fbc7e09b05ed29abe03"
	"e0561229ed0cb180f225a16acdb3868ba563c501425ff2df3564eedde40d29e55146c64beca4094de3dcbbeb59ff8399c817d4cb6721e02aa8761e2f25e13800")

package() {
	echo "Date and time classes for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
